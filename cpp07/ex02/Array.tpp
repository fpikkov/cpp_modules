#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array( unsigned int n ) :
	_array( n > 0 ? new T[n] : nullptr ), _size(n) {}

template <typename T>
Array<T>::Array( const Array& other ) { *this = other; }

template <typename T>
Array<T>& Array<T>::operator=( const Array& other )
{
	if (this != &other)
	{
		_size = other._size;
		_array = ( _size > 0 ? new T[_size] : nullptr );
		for (unsigned int idx = 0; idx < other._size; ++idx)
			_array[idx] = other._array[idx];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array() { delete[] _array; }

template <typename T>
T&	Array<T>::operator[]( unsigned int idx )
{
	if (idx >= _size)
		throw (std::out_of_range("accessor out of range"));
	return (_array[idx]);
}

template <typename T>
const T&	Array<T>::operator[]( unsigned int idx ) const
{
	if (idx >= _size)
		throw (std::out_of_range("accessor out of range"));
	return (_array[idx]);
}

template <typename T>
const unsigned int&	Array<T>::size() const noexcept { return (_size); }
