#pragma once

#include <chrono>
#include <vector>
#include <iostream>
#include <concepts>
#include <sstream>
#include <stdexcept>

#include "GroupIterator.hpp"

// Constants
static constexpr bool	const	COMPARISON_COUNTER	= true;
static constexpr bool	const	PRINT_LIMIT			= false;
static constexpr size_t const	PRINT_MAX			= 5;

/**
 * @brief Concept which checks (at compile time) that the container passed to us
 * can be used properly in the sorting algorithm.
 */
template <typename T, template <typename...> class Container>
concept iterable_container = requires
{
	typename Container<T>::value_type;
	typename Container<T>::iterator;

	// Check if the container has an iterator
	requires std::input_iterator<typename Container<T>::iterator>;

	// Check without constructing the container that the functionality matches allowed containers
	{ std::declval<Container<T>>().begin() }	-> std::same_as<typename Container<T>::iterator>;
	{ std::declval<Container<T>>().end() }		-> std::same_as<typename Container<T>::iterator>;
	{ std::declval<Container<T>>().empty() }	-> std::convertible_to<bool>;
};

template <std::integral T, template <typename...> class Container = std::vector>
requires iterable_container<T, Container>
class PmergeMe
{
	private:
		// ---------------- Type definitions -----------
		using duration			= std::chrono::duration<double, std::micro>;
		using size_type			= typename Container<GroupIterator<typename Container<T>::iterator>>::size_type;
		using difference_type	= typename Container<GroupIterator<typename Container<T>::iterator>>::difference_type;

		// ---------------- Member variables -----------
		Container<T>	_sequence;
		duration		_time;
		size_t			_comparisons;

		// ---------------- Member struct --------------
		template <typename GroupIt, typename MainIt = typename Container<GroupIt>::iterator>
		struct PendingGroup
		{
			GroupIt	follower;
			MainIt	upperLimit;
		};

		// ---------------- Storage --------------------
		void containerize( const std::string& values )
		{
			std::istringstream	sstream(values);
			T					value;

			while (sstream >> value)
				_sequence.insert(_sequence.end(), value);
			if (!sstream.eof())
				throw (std::runtime_error("Error: failed to parse integral values"));
		}

		// ---------------- Jacobsthal -----------------
		static size_type	jacobsthalGen( size_type n )		{ return (n <= 1 ? n : (jacobsthalGen(n - 1) + (2 * jacobsthalGen(n - 2)))); }

		static size_type	jacobsthal( size_type index )	{ return (jacobsthalGen(index + 3) - jacobsthalGen(index + 2)); }

	public:
		// ---------------- Rule of five ----------------
		PmergeMe() = delete;
		PmergeMe( const std::string& sequence ) : _comparisons(0)	{ containerize(sequence); }
		PmergeMe( const PmergeMe& ) = delete;
		PmergeMe& operator=( const PmergeMe& ) = delete;
		~PmergeMe() {}

		// ---------------- Getters ---------------------
		const Container<T>&	getSequence()		const	{ return (_sequence); }
		const duration&		getTime()			const	{ return (_time); }
		size_t				getComparisons()	const	{ return (_comparisons); }

		// ---------------- Helpers ---------------------
		void	printTime( const std::string& containerType ) const
		{
			std::cout << "Time to process a range of " << _sequence.size()
			<< " elements with std::" << containerType << " : " << _time << std::endl;
			if constexpr (COMPARISON_COUNTER)
				std::cout << "Comparisons: " << _comparisons << std::endl;
		}

		void	printContainer( const std::string& prefix ) const
		{
			std::cout << prefix;

			auto it = _sequence.begin();
			for (size_t idx = 0; idx < _sequence.size() && it != _sequence.end(); ++idx, ++it)
			{
				if (idx >= PRINT_MAX && PRINT_LIMIT)
				{
					std::cout << ' ' << "[...]";
					break ;
				}
				std::cout << ' ' << (*it);
			}
			std::cout << std::endl;
		}

		void	launch()
		{
			using Group = GroupIterator<typename Container<T>::iterator>;
			const auto start = std::chrono::high_resolution_clock::now();
			mergeInsert( Group(_sequence.begin(), 1),
						 Group(_sequence.end(), 1) );
			const auto end = std::chrono::high_resolution_clock::now();
			_time = end - start;
		}

		//NOTE: DEBUG
		int recursionLevel = 0;
		// ---------------- Sorting ---------------------
		template <typename Iterator = GroupIterator<typename Container<T>::iterator>>
		void	mergeInsert( Iterator first, Iterator last )
		{
			// Return if no more pairs can be formed
			size_type size	= std::distance(first, last);
			if ( size < 2 )
			{
				//NOTE: DEBUG
				--recursionLevel;
				return ;
			}

			// Last group will not be formed if the current sequence is odd
			bool is_odd		= size % 2;
			Iterator end	= is_odd ? std::prev(last) : last;

			// Step 1: Form groups then sort by the leading element
			for ( auto current = first; std::distance(current, end) > 0; current += 2 )
			{
				auto next = std::next(current);
				if constexpr (COMPARISON_COUNTER)
					++_comparisons;
				if ( current > next )
					current.swap_group(next);
			}
			//NOTE: DEBUG
			++recursionLevel;
			// Double up the size and recursively sort the groups in an ascending order.
			mergeInsert(first.expand(2), end.expand(2));

			// Step 2: Create the main and pending chains
			Container<Iterator>					main;
			Container<PendingGroup<Iterator>>	pending;

			// Insert first follower and leader into the main chain
			main.insert(main.end(), first);
			main.insert(main.end(), std::next(first));

			// Insert the remaining leaders into the main chain and followers into pending
			for ( auto current = first + 2; std::distance(current, end) > 0; current += 2 )
			{
				auto upper = main.insert(main.end(), std::next(current));
				pending.emplace(pending.end(), current, upper);
			}

			// Step 3: Insertion
			for ( size_type index = 0;; ++index )
			{
				size_type current = jacobsthal(index);
				if ( current > pending.size() )
					break ;

				// Insert 'current' ammount of elements into main
				for ( ; current > 0; --current )
				{
					auto element = std::next(pending.begin(), static_cast<difference_type>(current - 1));

					// Insert into the main using binary search
					auto pos = std::upper_bound(main.begin(), element->upperLimit, element->follower,
						[this]( const auto& lhs, const auto& rhs )
						{
							if constexpr (COMPARISON_COUNTER)
								++_comparisons;
							return (lhs < rhs);
						});
					main.insert(pos, element->follower);
					pending.erase(element);
				}
			}

			// Insert elements which when weren't inserted with jacobsthal's ordering
			while ( !pending.empty() )
			{
				auto element = std::next(pending.begin(), static_cast<difference_type>(pending.size() - 1));

				auto pos = std::upper_bound(main.begin(), element->upperLimit, element->follower,
					[this]( const auto& lhs, const auto& rhs )
					{
						if constexpr (COMPARISON_COUNTER)
							++_comparisons;
						return (lhs < rhs);
					});
				main.insert(pos, element->follower);
				pending.erase(element);
			}

			// Iterator invalidation prevents the inclusion of leftovers into the pending chain
			if ( is_odd )
			{
				auto pos = std::upper_bound(main.begin(), main.end(), end,
					[this]( const auto& lhs, const auto& rhs )
					{
						if constexpr (COMPARISON_COUNTER)
							++_comparisons;
						return (lhs < rhs);
					});
				main.insert(pos, end);
			}

			//NOTE: DEBUG
			std::cout << "Recursion level " << recursionLevel << " main: ";
			for (auto group : main)
			{
				std::cout << "| ";
				std::for_each(group.base(), group.end(),
				[](const auto& ch)
				{
					std::cout << ch << " ";
				});
			}
			std::cout << "\n";

			// Step 4: Update the sequence
			Container<T> temp;
			for ( const auto& group : main )
			{
				std::move(group.base(), group.end(), std::inserter(temp, temp.end()));
			}
			std::move(temp.begin(), temp.end(), first.base());
			//NOTE: DEBUG
			--recursionLevel;
		}
};


