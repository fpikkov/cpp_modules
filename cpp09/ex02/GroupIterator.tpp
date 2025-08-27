#include "GroupIterator.hpp"

// Getters

/**
 * @brief Fetches the value at the back of the group.
 * @return Value reference
 */
template <std::forward_iterator Iterator>
typename GroupIterator<Iterator>::reference
GroupIterator<Iterator>::back( void ) const
{
	Iterator temp = _it;
	std::advance(temp, _size - 1);
	return (*temp);
}

/**
 * @brief Fetches the iterator at the back of the group.
 * @return Underlying iterator
 */
template <std::forward_iterator Iterator>
Iterator
GroupIterator<Iterator>::back_iter( void ) const
{
	Iterator temp = _it;
	std::advance(temp, _size - 1);
	return (temp);
}

/**
 * @brief Fetches the value at the terminating end of the group.
 * @return Underlying iterator
 */
template <std::forward_iterator Iterator>
Iterator
GroupIterator<Iterator>::end( void ) const
{
	Iterator temp = _it;
	std::advance(temp, _size);
	return (temp);
}


// Swap groups

/**
 * @brief Swaps the current GroupIterator with the given GroupIterator.
 * @param other The group to swap with.
 * @return The next group from the end of the other group.
 */
template <std::forward_iterator Iterator>
GroupIterator<Iterator>
GroupIterator<Iterator>::swap_group( GroupIterator& other )
{
	std::swap_ranges(this->base(), this->end(), other.base());
	return ( GroupIterator(other.end(), other.size()) );
}

// Assignment operator overloads

template <std::forward_iterator Iterator>
GroupIterator<Iterator>&
GroupIterator<Iterator>::operator=( const GroupIterator& other )
{
	if ( this != &other )
	{
		_it		= other._it;
		_size	= other._size;
	}
	return (*this);
}

template <std::forward_iterator Iterator>
GroupIterator<Iterator>&
GroupIterator<Iterator>::operator=( GroupIterator&& other )
{
	if ( this != &other )
	{
		_it		= std::move(other._it);
		_size	= other._size;
	}
	return (*this);
}


// Increment/decrement operators

template <std::forward_iterator Iterator>
GroupIterator<Iterator>&
GroupIterator<Iterator>::operator++( void )
{
	std::advance(_it, _size);
	return (*this);
}

template <std::forward_iterator Iterator>
GroupIterator<Iterator>
GroupIterator<Iterator>::operator++( int )
{
	GroupIterator temp = *this;
	std::advance(_it, _size);
	return (temp);
}

/**
 * @brief Pre-decrements the current group by it's size.
 * Usable only with bi-directional iterators and it's supersets.
 * @return Reference to the current group.
 */
template <std::forward_iterator Iterator>
GroupIterator<Iterator>&
GroupIterator<Iterator>::operator--( void )
{
	if constexpr (_is_bidirectional)
	{
		std::advance(_it, -_size);
		return (*this);
	}
	else
		static_assert(_is_bidirectional, "Backwards iteration not supported for underlying iterator.");
}

/**
 * @brief Post-decrements the current group by it's size.
 * Usable only with bi-directional iterators and it's supersets.
 * @return Reference to the group before decrementing.
 */
template <std::forward_iterator Iterator>
GroupIterator<Iterator>
GroupIterator<Iterator>::operator--( int )
{
	if constexpr (_is_bidirectional)
	{
		GroupIterator temp = *this;
		std::advance(_it, -_size);
		return (temp);
	}
	else
		static_assert(_is_bidirectional, "Backwards iteration not supported for underlying iterator.");
}

template <std::forward_iterator Iterator>
GroupIterator<Iterator>&
GroupIterator<Iterator>::operator+=( difference_type dist )
{
	std::advance(_it, _size * dist);
	return (*this);
}

/**
 * @brief Subtracts a distance from the group and assigns it to the current group.
 * Usable only with bi-directional iterators and it's supersets.
 * @return Reference to the group after subtraction.
 */
template <std::forward_iterator Iterator>
GroupIterator<Iterator>&
GroupIterator<Iterator>::operator-=( difference_type dist )
{
	if constexpr (_is_bidirectional)
	{
		std::advance(_it, -(_size * dist));
		return (*this);
	}
	else
		static_assert(_is_bidirectional, "Backwards iteration not supported for underlying iterator.");
}


// Arithmetic operators

template <std::forward_iterator Iterator>
GroupIterator<Iterator>
GroupIterator<Iterator>::operator+( difference_type dist ) const
{
	Iterator temp = _it;
	std::advance(temp, _size * dist);
	return (GroupIterator(temp, _size));
}

/**
 * @brief Subtracts a distance from the group.
 * Usable only with bi-directional iterators and it's supersets.
 * @return New group at the given distance before the current group.
 */
template <std::forward_iterator Iterator>
GroupIterator<Iterator>
GroupIterator<Iterator>::operator-( difference_type dist ) const
{
	if constexpr (_is_bidirectional)
	{
		Iterator temp = _it;
		std::advance(temp, -(_size * dist));
		return (GroupIterator(temp, _size));
	}
	else
		static_assert(_is_bidirectional, "Backwards iteration not supported for underlying iterator.");
}

/**
 * @brief Finds the distance from the current group to the given group.
 * @return Distance between the groups based on the current group size.
 */
template <std::forward_iterator Iterator>
inline typename GroupIterator<Iterator>::difference_type
GroupIterator<Iterator>::operator-( const GroupIterator& other ) const
{
	return (std::distance(other._it, _it) / _size);
}


// Subscript operators

/**
 * @brief Fetches the element at the back of the group which is offset distance away from the current group.
 * @return Reference of the element at the back of the given offset.
 */
template <std::forward_iterator Iterator>
typename GroupIterator<Iterator>::reference
GroupIterator<Iterator>::operator[]( difference_type offset )
{
	Iterator temp = _it;
	std::advance(temp, (_size * offset) + (_size - 1));
	return (*temp);
}

/**
 * @brief Fetches the element at the back of the group which is offset distance away from the current group.
 * @return Constant reference of the element at the back of the given offset.
 */
template <std::forward_iterator Iterator>
const typename GroupIterator<Iterator>::reference
GroupIterator<Iterator>::operator[]( difference_type offset ) const
{
	Iterator temp = _it;
	std::advance(temp, (_size * offset) + (_size - 1));
	return (*temp);
}
