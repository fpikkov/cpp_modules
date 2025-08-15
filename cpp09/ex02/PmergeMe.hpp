#pragma once

#include <chrono>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <concepts>
#include <sstream>
#include <stdexcept>

// How many contained elements to print out.
static constexpr bool			PRINT_LIMIT	= true;
static constexpr size_t const	PRINT_MAX	= 5;

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
		PmergeMe( const std::string& sequence )	{ containerize(sequence); }
		PmergeMe( const PmergeMe& ) = delete;
		PmergeMe& operator=( const PmergeMe& ) = delete;
		~PmergeMe() {}

		// ---------------- Getters ---------------------
		const Container&	getSequence()	const	{ return (_sequence); }
		const duration&		getTime()		const	{ return (_time); }

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
		void	mergeInsert( Container& seq )
		{

		}
};


