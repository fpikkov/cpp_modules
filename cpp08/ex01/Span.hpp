#pragma once

#include <vector>
#include <span>
#include <algorithm>
#include <stdexcept>
#include <limits>

#define MIN_SPAN_SIZE 2

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_vec;

	public:
		Span() = delete;
		Span( const unsigned int& );
		Span( const Span& );
		Span&	operator=( const Span& );
		~Span();

		void	addNumber( const int& );
		void	addNumbers( std::span<const int> );
		auto	shortestSpan() -> unsigned int;
		auto	longestSpan() -> unsigned int;
};
