#pragma once

#include <chrono>
#include <vector>
#include <iostream>
#include "ft.hpp"

#define PRINT_MAX 5

template <std::integral T, ft::container C = std::vector<T>>
class PmergeMe
{
	private:
		using duration = std::chrono::duration<double, std::micro>;

		C			_original;
		C			_sorted;
		duration	_time;

		auto printContainer( const C container ) const -> void
		{
			auto it = container.begin();
			for (size_t idx = 0; idx < container.size() && !(idx > PRINT_MAX) && it != container.end(); ++idx, ++it)
			{
				if (idx < PRINT_MAX)
					std::cout << ' ' << (*it);
				else
					std::cout << ' ' << "[...]";
			}
			std::cout << std::endl;
		}

	public:
		PmergeMe() = delete;
		PmergeMe( C values )
		{
			for ( auto& v : values )
				_original.insert(_original.end(), v);
		}
		PmergeMe( const PmergeMe& ) = delete;
		PmergeMe& operator=( const PmergeMe& ) = delete;
		~PmergeMe() {}

		auto getOriginal() const -> const C& { return (_original); }
		auto getSorted() const -> const C& { return (_sorted); }
		auto getTime() const -> const duration& { return (_time); }

		auto printInfo() const -> void
		{
			std::cout << "Before:";
			printContainer(_original);
		}
		auto printTime( const std::string& cType ) const -> void
		{
			std::cout << "Time to process a range of\t" << _sorted.size()
			<< " elements with std::" << cType << " : " << _time << std::endl;
		}
		auto launch() -> void
		{
			const auto start = std::chrono::high_resolution_clock::now();
			// TODO: Sort the numbers
			const auto end = std::chrono::high_resolution_clock::now();
			_time = end - start;
		}
};