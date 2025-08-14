#pragma once

#include <chrono>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <concepts>
#include <sstream>
#include <stdexcept>

static constexpr size_t const PRINT_MAX = 5;

template <typename T>
concept container = requires( T type )
{
	typename T::value_type;
	typename T::iterator;
	{ type.begin() } -> std::input_iterator;
	{ type.end() } -> std::input_iterator;
	{ type.empty() } -> std::same_as<decltype(type.empty())>;
};

template <std::integral T, container Container = std::vector<T>>
class PmergeMe
{
	private:
		using duration = std::chrono::duration<double, std::microx>;

		Container	_sequence;
		duration	_time;

		void containerize( const std::string& str )
		{
			std::istringstream	sstream(str);
			T					value;

			while (sstream >> value)
				_sequence.insert(values.end(), value);
			if (!sstream.eof())
				throw (std::runtime_error("Error: failed to parse integral values"));
		}

	public:
		// Rule of five
		PmergeMe() = delete;
		PmergeMe( const std::string& sequence )	{ containerize(sequence); }
		PmergeMe( const PmergeMe& ) = delete;
		PmergeMe& operator=( const PmergeMe& ) = delete;
		~PmergeMe() {}

		// Getters
		const Container&	getSequence()	const	{ return (_sequence); }
		const duration&		getTime()		const	{ return (_time); }

		// Helpers
		void	printTime( const std::string& cType ) const
		{
			std::cout << "Time to process a range of " << _sorted.size()
			<< " elements with std::" << cType << " : " << _time << std::endl;
		}

		void	printContainer( const std::string& prefix ) const
		{
			std::cout << prefix;

			auto it = _sequence.begin();
			for (size_t idx = 0; idx < cont.size() && !(idx > PRINT_MAX) && it != _sequence.end(); ++idx, ++it)
			{
				if (idx < PRINT_MAX)
					std::cout << ' ' << (*it);
				else
					std::cout << ' ' << "[...]";
			}
			std::cout << std::endl;
		}

		void	launch()
		{
			const auto start = std::chrono::high_resolution_clock::now();
			mergeInsert(_sequence);
			const auto end = std::chrono::high_resolution_clock::now();
			_time = end - start;
		}

		// Sorting
		void	mergeInsert( Container& seq )
		{
			// TODO: Need to create the same container but with std::pair<T, T> as the type
			// This is required for the merge portion of the allgorithm
		}
};

std::string	args_to_string( int argc, char** argv );
