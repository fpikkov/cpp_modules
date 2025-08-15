#pragma once

#include <chrono>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <concepts>
#include <sstream>
#include <stdexcept>

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
		using pair_type	= std::pair<T, T>;

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
		// On entry the container may be the non-const reference to mainChain
		void	mergeInsert( Container& seq )
		{
			// NOTE: Do I flush and construct a new 'seq' here?
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

				// NOTE: Do I pass the mainChain recursively or flush seq and reuse that?
				mainChain.push_back(lastPair.second);
			}

			/**
			 * NOTE: The 'seq' container should be flushed but first we need to keep track
			 * of the first elements in pairs but also any leftovers which become the pending chain.
			 */
			// Recursive call (branching point)
			mergeInsert(mainChain);

			/**
			 * NOTE: how should I track which pair ended up as the first one during recursion?
			 */

			// Push the leftover element into pending after returning from recursion
			if (seq.size() % 2)
				pending.push_back(seq.back());
		}
};


