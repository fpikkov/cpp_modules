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
static constexpr bool	const	PRINT_LIMIT			= true;
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
		}

		void	printContainer( const std::string& prefix ) const
		{
			std::cout << prefix;

			auto it = _sequence.begin();
			for (size_t idx = 0; idx < _sequence.size() && (idx < PRINT_MAX && PRINT_LIMIT) && it != _sequence.end(); ++idx, ++it)
				std::cout << ' ' << (*it);
			if constexpr (PRINT_LIMIT)
				std::cout << ' ' << "[...]";
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
			size_t size = std::distance(first, last);
			if ( size < 2 )
				return ;

			// Last group will not be formed if the current sequence is odd
			bool is_odd = size % 2;
			Iterator end = is_odd ? std::prev(last) : last;

			// Step 1: Form groups then sort by the leading element
			for ( auto current = first; current.base() != end.end(); std::advance(current, current.size()) )
			{
				auto next = std::next(current);
				if constexpr (COMPARISON_COUNTER)
					++_comparisons;
				if ( current > next )
					current.swap_group(next);
			}
			// NOTE: Before recursion expand the first and last iterators.
			mergeInsert(first.expand(2), end.expand(2));
			// NOTE: May have to shrink the same iterators after returning unless
			// creating new instances for recursion.


		}
};


