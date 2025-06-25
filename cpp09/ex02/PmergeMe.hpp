#pragma once

#include <chrono>
#include <vector>
#include <utility>
#include <optional>
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
		bool		_numbersSorted;

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
		auto recurse( C cont ) -> C
		{
			using value_type = typename C::value_type; // integral or pair
			using pair = std::pair<value_type, value_type>; // new pair gets defined during recursion

			std::optional<value_type> unpairable;
			C<pair> current;

			if (cont.size() <= 1)
				return (cont);

			for ( auto it = cont.begin(); it != cont.end();; )
			{
				value_type a = *it++;
				if ( it != cont.end() )
				{
					value_type b = (*it);
					current.emplace_back(ft::make_ordered_pair(a, b));
				}
				else
					unpairable = a;
			}

/*			stores the unpairable part but in the _sorted container?
			if (unpairable.has_value())
			{
				// Reqires cusstom comparator which would check the rightmost value. Otherwise pair into { max, min }
				auto pos = std::lower_bound(_sorted.begin(), _sorted.end(), unpairable.value());
				_sorted.insert(pos, unpairable.value());
			}
			return (_sorted);
 */
		}

	public:
		PmergeMe() = delete;
		PmergeMe( C values ) : _numbersSorted(false)
		{
			for ( auto& v : values )
				_original.insert(_original.end(), v);
			checkIfSorted();
		}
		PmergeMe( const PmergeMe& ) = delete;
		PmergeMe& operator=( const PmergeMe& ) = delete;
		~PmergeMe() {}

		auto getOriginal() const -> const C& { return (_original); }
		auto getSorted() const -> const C& { return (_sorted); }
		auto getTime() const -> const duration& { return (_time); }

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
			}
			_numbersSorted = true;
			return (_numbersSorted);
		}
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
			if (_numbersSorted)
			{
				std::cout << "Given numbers are already sorted." << std::endl;
				return ;
			}
			const auto start = std::chrono::high_resolution_clock::now();
			// TODO: Sort the numbers
			const auto end = std::chrono::high_resolution_clock::now();
			_time = end - start;
		}
};
