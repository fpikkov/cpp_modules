/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:32:28 by fpikkov           #+#    #+#             */
/*   Updated: 2025/04/30 13:32:30 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	PRINT("Default constructor called");
	number = 0;
}

Fixed::Fixed( const int value )
{
	// Accepts integer
}

Fixed::Fixed( const float value )
{
	// Accepts float
}

Fixed::Fixed(const Fixed& other )
{
	PRINT("Copy constructor called");
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	PRINT("Copy assignment operator called");
	this->number = other.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	PRINT("Destructor called");
}

/**
 * @brief Returns the raw value of the fixed-point value
 */
int		Fixed::getRawBits( void ) const
{
	PRINT("getRawBits member function called");
	return (number >> fractional_bits);
}

/**
 * @brief Sets the raw value of the fixed-point number
 */
void	Fixed::setRawBits( int const raw)
{
	PRINT("setRawBits member function called");
	number = raw << fractional_bits;
}

float	Fixed::toFloat( void ) const
{
	// Converts to float
}

int		Fixed::toInt( void ) const
{
	// Convert to int
}

std::ostream& operator<<( std::ostream& os, const Fixed& obj)
{
	os << obj.getRawBits();
	return (os);
}
