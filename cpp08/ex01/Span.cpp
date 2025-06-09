#include "Span.hpp"

// Canonical formx
Span::Span( const unsigned int& N ) :
	_size( N < _vec.max_size() ? N : throw(std::overflow_error("Container can not store that many elements"))) {}
Span::Span( const Span& other ) { *this = other; }
Span&	Span::operator=( const Span& other )
{
	if (this != &other)
	{
		_vec.clear();
		_size = other._size;
		for (auto& v : other._vec)
		{
			if (_vec.size() + 1 > _size)
				throw(std::out_of_range("unable to store more integers"));
			_vec.push_back(v);
		}
	}
	return (*this);
}
Span::~Span() {}

// Member functions
void	Span::addNumber( const int& number )
{
	if (_vec.size() + 1 > _size)
		throw(std::out_of_range("unable to store more integers"));
	_vec.push_back(number);
}

void	Span::addNumbers( std::span<const int> numbers )
{
	if (_vec.size() + numbers.size() > _size)
		throw(std::out_of_range("unable to store more integers"));
	_vec.insert(_vec.end(), numbers.begin(), numbers.end());
}

auto	Span::shortestSpan() -> unsigned int
{
	if (_vec.size() > _size)
		throw(std::out_of_range("found more integers than expected"));
	else if (_vec.size() < MIN_SPAN_SIZE)
		throw(std::length_error("not enough integers to find a span"));

	std::sort(_vec.begin(), _vec.end(), []( int a, int b ) { return (a <= b); });

	unsigned int result = std::numeric_limits<unsigned int>::max();

	for (auto it = _vec.begin(); it != _vec.end() - 1; ++it)
	{
		unsigned int temp = static_cast<unsigned int>(*(it + 1) - (*it));
		if (temp < result)
			result = temp;
	}
	return (result);
}

/**
 * @brief Finds the longest span of integers within the vector
 * @return Distance between the lowest and the greatest integer
 */
auto	Span::longestSpan() -> unsigned int
{
	if (_vec.size() > _size)
		throw(std::out_of_range("found more integers than expected"));
	else if (_vec.size() < MIN_SPAN_SIZE)
		throw(std::length_error("not enough integers to find a span"));

	std::sort(_vec.begin(), _vec.end(), []( int a, int b ) { return (a <= b); });

	auto it_min = std::min_element(_vec.begin(), _vec.end());
	auto it_max = std::max_element(_vec.begin(), _vec.end());

	return ( static_cast<unsigned int>((*it_max) - (*it_min)));
}
