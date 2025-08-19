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
		const Container&	getSequence()		const	{ return (_sequence); }
		const duration&		getTime()			const	{ return (_time); }
		size_t				getComparisons()	const	{ return (_comparisons); }

		// ---------------- Helpers ---------------------
		void	printTime( const std::string& containerType ) const
		{
			std::cout << "Time to process a range of " << _sorted.size()
			<< " elements with std::" << containerType << " : " << _time << std::endl;
		}

		void	printContainer( const std::string& prefix ) const
		{
			std::cout << prefix;

			auto it = _sequence.begin();
			for (size_t idx = 0; idx < cont.size() && (idx < PRINT_MAX && PRINT_LIMIT) && it != _sequence.end(); ++idx, ++it)
				std::cout << ' ' << (*it);
			if constexpr (PRINT_LIMIT)
				std::cout << ' ' << "[...]";
			std::cout << std::endl;
		}

		void	launch()
		{
			const auto start = std::chrono::high_resolution_clock::now();
			mergeInsert(_sequence);
			const auto end = std::chrono::high_resolution_clock::now();
			_time = end - start;
		}

		// ---------------- Sorting ---------------------

		template <typename Iterator>
		void	mergeInsert( Iterator first, Iterator last )
		{
			// Return if no more pairs can be mmerged
			size_t size = std::distance(first, last);
			if ( size < 2 )
				return ;

			// Store the last iterator if size is odd
			bool is_odd = size % 2;
			Iterator leftover;
			if ( is_odd )
			{
				leftover = last;
				last = std::prev(last);
			}

			// Step 1: Form groupings then sort by the leading element




		}



/*
		// On entry the container may be the non-const reference to mainChain OR _sequence
		void	mergeInsert( Container& seq )
		{
			if (seq.size() <= 1)
				return ;

			Container<T>			mainChain;
			Container<T>			pending;
			Container<pair_type>	pairs;

			// Make pairs out of sequence
			for ( auto it : seq )
			{
				auto itx = std::next(it);
				if ( itx == seq.end() )
					break ;
				// Compare and swap positions so first < second
				pairs.push_back(std::make_pair(*it, *itx));
				auto lastPair = pairs.back();
				if (lastPair.first > lastPair.second)
					std::swap(lastPair.first, lastPair.second);
				if constexpr (COMPARISON_COUNTER)
					++_comparisons;

				// NOTE: I should pass 'mainChain' recursively otherwise we risk losing data from 'seq'
				mainChain.push_back(lastPair.second);
			}

			// TODO: Track first elements and leftovers in 'pending'
			//
			// In case of [10 10 9 7] where the mainChain ends up looking like [9 10] post-recursion,
			// you can track the original index of the value which endds up as first during recursion
			// AND return the value back to the layer above.

			// Recursive call (branching point)
			mergeInsert(mainChain);

			// NOTE: how should I track which pair ended up as the first one during recursion?
			// ANSWER: You can track the first pair by storing its index or value before recursion.
			//         For example, save the first element of 'mainChain' or 'pairs' before calling mergeInsert.
			//         If you need to know which pair was first after recursion, you may need to return that info from the recursive call.

			// Push the leftover element into pending after returning from recursion
			if (seq.size() % 2)
				pending.push_back(seq.back());
		}
		 */
};


