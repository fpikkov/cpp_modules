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
		using duration	= std::chrono::duration<double, std::micro>;

		// ---------------- Member variables -----------
		Container<T>	_sequence;
		duration		_time;
		size_t			_comparisons;

		// ---------------- Member struct --------------
		template <typename GroupIt, typename MainIt = typename Container<GroupIt>::iterator>
		struct PendingGroup
		{
			GroupIt	follower;
			MainIt	upperBound;
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
		static unsigned long	jacobsthal( unsigned long n )
		{
			if ( n <= 1 )
				return (n);
			return (jacobsthal(n - 1) + (2 * jacobsthal(n - 2)));
		}

		static unsigned long	specialOrder( unsigned int index )
		{
			return (jacobsthal(index + 3) - jacobsthal(index + 2));
		}

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
			size_t size	= std::distance(first, last);
			if ( size < 2 )
				return ;

			// Last group will not be formed if the current sequence is odd
			bool is_odd		= size % 2;
			Iterator end	= is_odd ? std::prev(last) : last;

			// Step 1: Form groups then sort by the leading element
			for ( auto current = first; current.base() != end.base(); current += 2 )
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
			Container<Iterator>					main;
			Container<PendingGroup<Iterator>>	pending;

			// Insert first follower and leader into the main chain
			main.insert(main.end(), first);
			main.insert(main.end(), std::next(first));

			// Insert the remaining leaders into the main chain and followers into pending
			for ( auto current = first + 2; current.base() != end.base(); current +=2 )
			{
				auto upper = main.insert(main.end(), std::next(current));
				pending.emplace(pending.end(), current, upper);
			}

			// If leftover exists, append it to the pending chain
			if ( is_odd )
				pending.emplace(pending.end(), end, main.end());

			// If pending is empty, skip to restructuring the original sequence

			// QUESTION: How do we figure out which jacobsthal number we should use during the current recurison level?

			// During insertion the whole group gets placed somewhere before the upper bound.

			// Whenever returning from recursion, we need to restructure the original iterator order.
			// Due to the nature of recursive insertion, this will reflect a partially sorted sequence in the escaped recursive level.


		}
};


