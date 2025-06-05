#pragma once

#include <stdexcept>

template <typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array();
		Array( unsigned int n );
		Array( const Array& );
		Array& operator=( const Array& );
		~Array();

		T&					operator[]( unsigned int idx );
		const T&			operator[]( unsigned int idx ) const;
		const unsigned int&	size() const noexcept;
};

#include "Array.tpp"
