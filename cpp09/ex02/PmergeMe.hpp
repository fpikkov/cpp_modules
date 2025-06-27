#pragma once

#include <chrono>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include "ft.hpp"

#define PRINT_MAX 5

template <std::integral T, ft::container Container = std::vector<T>>
class PmergeMe
{
	private:
		using duration = std::chrono::duration<double, std::micro>;

		Container	_original;
		Container	_sorted;
		duration	_time;
		bool		_numbersSorted;
		size_t		_grouping;
		size_t		_comparisons;

		auto printContainer( const Container cont ) const -> void
		{
			auto it = cont.begin();
			for (size_t idx = 0; idx < cont.size() && !(idx > PRINT_MAX) && it != cont.end(); ++idx, ++it)
			{
				if (idx < PRINT_MAX)
					std::cout << ' ' << (*it);
				else
					std::cout << ' ' << "[...]";
			}
			std::cout << std::endl;
		}
		auto sortPairs() -> void // Step 1 of the Ford-Johnson algorithm
		{
			size_t groupSize = 1 << _grouping;
			auto it = _sorted.begin();
			auto ite = _sorted.end();

			if ( std::ranges::distance(it, ite) < static_cast<std::ptrdiff_t>(2 * groupSize) ) // Go to steps 2 and 3
				return ;
			while ( std::ranges::distance(it, ite) >= static_cast<std::ptrdiff_t>(2 * groupSize) )
			{
				auto first_begin = it;
				auto second_begin = std::next(first_begin, groupSize);

				T first_max = *std::max_element(first_begin, second_begin);
				T second_max = *std::max_element(second_begin, std::next(second_begin, groupSize));
				++_comparisons;

				if ( first_max > second_max )
					std::swap_ranges(first_begin, second_begin, second_begin);

				std::advance(it, 2 * groupSize);
			}

			++_grouping;
			sortPairs();
		}
		auto checkIfSorted() -> bool
		{
			auto it = _original.begin();
			auto ite = _original.end();

			if (it == ite)
				throw (std::runtime_error("No values to sort"));

			auto temp = (*it);

			for (; it != ite; ++it )
			{
				if ( temp > (*it) )
					return (_numbersSorted);
				temp = (*it);
			}
			_numbersSorted = true;
			return (_numbersSorted);
		}

	public:
		PmergeMe() = delete;
		PmergeMe( Container values ) : _numbersSorted(false), _grouping(0), _comparisons(0)
		{
			for ( auto& v : values )
			{
				_original.insert(_original.end(), v);
				_sorted.insert(_sorted.end(), v);
			}
			checkIfSorted();
		}
		PmergeMe( const PmergeMe& ) = delete;
		PmergeMe& operator=( const PmergeMe& ) = delete;
		~PmergeMe() {}

		auto getOriginal() const -> const Container& { return (_original); }
		auto getSorted() const -> const Container& { return (_sorted); }
		auto getTime() const -> const duration& { return (_time); }
		auto getComparisons() const -> const size_t& { return (_comparisons); }

		auto printBefore() const -> void
		{
			std::cout << "Before:";
			printContainer(_original);
		}
		auto printAfter() const -> void
		{
			std::cout << "After:";
			printContainer(_sorted);
		}
		auto printTime( const std::string& cType ) const -> void
		{
			std::cout << "Time to process a range of " << _sorted.size()
			<< " elements with std::" << cType << " : " << _time << std::endl;
		}
		auto printComparisons() const -> void
		{
			std::cout << "Performed comparisons: " << _comparisons << std::endl;
		}

		auto launch() -> void
		{
			if (_numbersSorted)
			{
				std::cout << "Given numbers are already sorted." << std::endl;
				return ;
			}
			const auto start = std::chrono::high_resolution_clock::now();
			// TODO: Sort the numbers
			// ----- TESTING --------
			sortPairs();
			// ----- ------- --------
			const auto end = std::chrono::high_resolution_clock::now();
			_time = end - start;
			_numbersSorted = true;
		}
};
