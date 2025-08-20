#pragma once

#include <iterator>
#include <algorithm>

/**
 * @author fpikkov
 * @brief Groups a range of iterators.
 * @details The class can be used to compare the greatest back elements from two groups.
 * Comparisons are between groups of different sizes are valid, but can lead to unefined behavior.
 * Any container size has to be casted into difference_type before class instantiation.
 * Subscript operator will return the element at the back of the group with an offset from the current group.

 *
 * @tparam Iterator The container's iterator type.
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
		Iterator		base		( void )						const	{ return (_it); }
		difference_type	size		( void )						const	{ return (_size); }
		reference		back		( void )						const	{ return (*(_it + (_size - 1))); }
		Iterator		back_iter	( void )						const	{ return (_it + (_size - 1)); }
		Iterator		end			( void )						const	{ return (_it + _size); }

		// Size manipulation
		GroupIterator	resize		( difference_type size )		const	{ return (GroupIterator(_it, (size > 0 ? size : 1))); }
		GroupIterator&	resize		( difference_type size )				{ _size = (size > 0 ? size : 1); return (*this); }

		GroupIterator	expand		( difference_type size )		const	{ return (GroupIterator(_it, _size * (size > 0 ? size : 1))); }
		GroupIterator&	expand		( difference_type size )				{ _size *= (size > 0 ? size : 1); return (*this); }

		GroupIterator	shrink		( difference_type size )		const	{ return (GroupIterator(_it, _size / (size > 0 ? size : 1))); }
		GroupIterator&	shrink		( difference_type size )				{ _size /= (size > 0 ? size : 1); return (*this); }

		// Swap groups
		GroupIterator	swap_group	( GroupIterator& other )
		{
			std::swap_ranges(this->base(), this->end(), other.base());
			return ( GroupIterator(other.end(), other.size()) );
		}

		// Assignment operator overloads
		GroupIterator&	operator=	( const GroupIterator& other )
		{
			if ( this != &other )
			{
				_it		= other._it;
				_size	= other._size;
			}
			return (*this);
		}
		GroupIterator&	operator=	( GroupIterator&& other )
		{
			if ( this != &other )
			{
				_it		= std::move(other._it);
				_size	= other._size;
			}
			return (*this);
		}

		// Dereference operators
		reference		operator*	( void )						const	{ return (*_it); }
		pointer			operator->	( void )						const	{ return (&(*_it)); }

		// Increment/decrement operators
		GroupIterator&	operator++	( void )								{ _it += _size; return (*this); }
		GroupIterator	operator++	( int )									{ GroupIterator temp = _it; _it += _size; return (temp); }
		GroupIterator&	operator--	( void )								{ _it -= _size; return (*this); }
		GroupIterator	operator--	( int )									{ GroupIterator temp = _it; _it -= _size; return (temp); }
		GroupIterator&	operator+=	( difference_type dist )				{ _it += _size * dist; return (*this); }
		GroupIterator&	operator-=	( difference_type dist )				{ _it -= _size * dist; return (*this); }

		// Arithmetic operators
		GroupIterator	operator+	( difference_type dist )		const	{ return (GroupIterator(_it + _size * dist, _size)); }
		GroupIterator	operator-	( difference_type dist )		const	{ return (GroupIterator(_it - _size * dist, _size)); }
		difference_type	operator-	( const GroupIterator& other )	const	{ return ((_it - other._it) / _size); }

		// Subscript operators
		reference		operator[]	( difference_type offset )				{ return (*(_it + (_size * offset) + (_size - 1))); }
		const reference	operator[]	( difference_type offset )		const	{ return (*(_it + (_size * offset) + (_size - 1))); }

		// Comparison operators
		bool			operator<	( const GroupIterator& other )	const	{ return (this->back() < other.back()); }
		bool			operator>	( const GroupIterator& other )	const	{ return (this->back() > other.back()); }
		bool			operator<=	( const GroupIterator& other )	const	{ return (this->back() <= other.back()); }
		bool			operator>=	( const GroupIterator& other )	const	{ return (this->back() >= other.back()); }
		bool			operator==	( const GroupIterator& other )	const	{ return (this->back() == other.back()); }
		bool			operator!=	( const GroupIterator& other )	const	{ return (this->back() != other.back()); }
};
