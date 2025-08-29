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

/**
 * @brief Concept checks if we can reserve space within the container.
 */
template <typename T, template <typename...> class Container>
concept has_reserve = requires
{
	typename Container<T>::size_type;

	{ std::declval<Container<T>>().reserve(std::declval<typename Container<T>::size_type>()) } -> std::same_as<void>;
};

/**
 * @brief Concept checks if we can push or emplace elements to the back with the given container.
 */
template <typename T, template <typename...> class Container>
concept has_push_back = requires
{
	typename Container<T>::value_type;

	{ std::declval<Container<T>>().push_back(std::declval<typename Container<T>::value_type>()) } -> std::same_as<void>;
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

		// ---------------- Sorting ---------------------
		template <typename Iterator = GroupIterator<typename Container<T>::iterator>>
		void	mergeInsert( Iterator first, Iterator last )
		{
			// Return if no more pairs can be formed
			size_type size	= std::distance(first, last);
			if ( size < 2 )
				return ;

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
			// Double up the size and recursively sort the groups in an ascending order.
			mergeInsert(first.expand(2), end.expand(2));

			// Step 2: Create the main and pending chains
			Container<Iterator>	main;
			Container<Iterator>	pending;

			// Optimization for vectors
			if constexpr ( has_reserve<T, Container> )
			{
				main.reserve(size);
				pending.reserve((size + 1) / 2 - 1);
			}

			// Insert first follower and leader into the main chain
			if constexpr ( has_push_back<T, Container> )
			{
				main.push_back(first);
				main.push_back(std::next(first));
			}
			else
			{
				main.insert(main.end(), first);
				main.insert(main.end(), std::next(first));
			}

			// Insert the remaining leaders into the main chain and followers into pending
			for ( auto current = first + 2; std::distance(current, end) > 0; current += 2 )
			{
				if constexpr ( has_push_back<T, Container> )
				{
					pending.emplace_back(current);
					main.push_back(std::next(current));
				}
				else
				{
					pending.emplace(pending.end(), current);
					main.insert(main.end(), std::next(current));
				}
			}

			// Include leftover element in the pending chain
			if ( is_odd )
			{
				if constexpr ( has_push_back<T, Container> )
					pending.emplace_back(end);
				else
					pending.emplace(pending.end(), end);
			}

			// Step 3: Insertion
			size_type previousNumber	= jacobsthalGen(1);
			size_type insertions		= 0;
			auto lastSequenceEnd		= pending.begin();

			// Jacobsthal sequence insertion
			for ( size_type k = 2;; ++k )
			{
				size_type currentNumber	= jacobsthalGen(k);
				size_type difference	= currentNumber - previousNumber;
				size_type leaderShift	= 0;
				size_type remaining		= std::distance(lastSequenceEnd, pending.end());

				if ( difference > remaining )
					break;

				for ( size_type amount = difference; amount > 0; --amount )
				{
					auto follower		= std::next(lastSequenceEnd, static_cast<difference_type>(amount - 1));
					auto upperBoundary	= std::next(main.begin(), static_cast<difference_type>(currentNumber + insertions - leaderShift));

					auto insertionPoint = std::upper_bound(main.begin(), upperBoundary, *follower,
						[this](const auto& lhs, const auto& rhs) {
							if constexpr (COMPARISON_COUNTER)
								++_comparisons;
							return (lhs < rhs);
						});

					auto insertionIt = main.insert(insertionPoint, *follower);

					if ( std::distance(main.begin(), insertionIt) == static_cast<difference_type>(currentNumber + insertions) )
						++leaderShift;
				}
				previousNumber	= currentNumber;
				insertions		+= difference;
				leaderShift		= 0;

				std::advance(lastSequenceEnd, static_cast<difference_type>(difference));
			}

			// Insert remaining elements
			size_type remaining = std::distance(lastSequenceEnd, pending.end());
			for (difference_type i = static_cast<difference_type>(remaining) - 1; i >= 0; --i)
			{
				auto follower		= std::next(lastSequenceEnd, i);
				auto upperBoundary	= std::next(main.begin(), static_cast<difference_type>(main.size() - remaining + static_cast<size_type>(i) + is_odd));

				auto insertionPoint = std::upper_bound(main.begin(), upperBoundary, *follower,
					[this](const auto& lhs, const auto& rhs) {
						if constexpr (COMPARISON_COUNTER)
							++_comparisons;
						return (lhs < rhs);
					});

				main.insert(insertionPoint, *follower);
			}

			pending.clear();

			// Step 4: Update the sequence
			Container<T> temp;
			for ( const auto& group : main )
			{
				std::move(group.base(), group.end(), std::inserter(temp, temp.end()));
			}
			std::move(temp.begin(), temp.end(), first.base());
		}
};


