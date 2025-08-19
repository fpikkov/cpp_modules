#pragma once

#include <iterator>
#include <algorithm>

/**
 * @brief Groups a range of iterators which can then be used to compare the greatest elements from two groups.
 * Comparisons are possible to be used on groups of different sizes so it is up to the user to make sure they are equal.
 * @tparam Iterator The iterator type to be used.
 * @author fpikkov
 */
template <typename Iterator>
class GroupIterator
{
	public:
		// Type definitions
		using iterator_category	= std::random_access_iterator_tag;
		using value_type		= typename std::iterator_traits<Iterator>::value_type;
		using difference_type	= typename std::iterator_traits<Iterator>::difference_type;
		using pointer			= typename std::iterator_traits<Iterator>::pointer;
		using reference			= typename std::iterator_traits<Iterator>::reference;

	private:
		Iterator		_it;
		difference_type	_size;

	public:
		// Constructors
		GroupIterator() = default;
		GroupIterator( Iterator first, Iterator last ) :
			_it(first), _size(std::distance(first, last)) {}
		GroupIterator( Iterator first, difference_type size ) :
			_it(first), _size(size) {}
		GroupIterator( const GroupIterator& other ) :
			_it(other._it), _size(other._size) {}
		GroupIterator( GroupIterator&& other ) :
			_it(std::move(other._it)), _size(other._size) {}
		~GroupIterator() {};

		// Getters
		Iterator		base()		const { return (_it); }
		difference_type	size()		const { return (_size); }
		reference		back()		const { return (*(_it + (size - 1))); }
		Iterator		back_iter()	const { return (_it + (size - 1)); }

		// Resize current group
		GroupIterator	resize( difference_type size ) const { return (GroupIterator(_it, _size * size)) }
		GroupIterator&	resize( difference_type size )       { _size *= size; return (*this); }

		// Assignment operator overloads
		GroupIterator&	operator=( const GroupIterator& other )
		{
			if ( this != &other )
			{
				_it		= other._it;
				_size	= other._size;
			}
			return (*this);
		}
		GroupIterator&	operator=( GroupIterator&& other )
		{
			if ( this != &other )
			{
				_it		= std::move(other._it);
				_size	= other._size;
			}
			return (*this);
		}

		// Dereference operators
		reference		operator*()		const { return (*_it); }
		pointer			operator->()	const { return (&(*_it)); }

		// Increment/decrement operators
		GroupIterator&	operator++()						{ _it += _size; return (*this); }
		GroupIterator	operator++( int )					{ GroupIterator temp = _it; _it += _size; return (temp); }
		GroupIterator&	operator--()						{ _it -= _size; return (*this); }
		GroupIterator	operator--( int )					{ GroupIterator temp = _it; _it -= _size; return (temp); }
		GroupIterator&	operator+=( difference_type dist )	{ _it += _size * dist; return (*this); }
		GroupIterator&	operator-=( difference_type dist )	{ _it -= _size * dist; return (*this); }

		// Arithmetic operators
		GroupIterator	operator+( difference_type dist )		const { return (GroupIterator(_it + _size * dist, _size)); }
		GroupIterator	operator-( difference_type dist )		const { return (GroupIterator(_it - _size * dist, _size)); }
		difference_type	operator-( const GroupIterator& other )	const { return ((_it - other._it) / _size); }

		// Subscript operators
		reference		operator[]( difference_type pos )       { return (*(_it + _size * pos)); }
		const reference	operator[]( difference_type pos ) const { return (*(_it + _size * pos)); }

		// Comparison operators
		bool			operator<( const GroupIterator& other )  const { return (this->back() < other.back()); }
		bool			operator>( const GroupIterator& other )  const { return (this->back() > other.back()); }
		bool			operator<=( const GroupIterator& other ) const { return (this->back() <= other.back()); }
		bool			operator>=( const GroupIterator& other ) const { return (this->back() >= other.back()); }
		bool			operator==( const GroupIterator& other ) const { return (this->back() == other.back()); }
		bool			operator!=( const GroupIterator& other ) const { return (this->back() != other.back()); }
};
