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
	raw = 0;
}

Fixed::Fixed( const int value )
{
	PRINT("Int constructor called");
	raw = static_cast<int>(value * (1 << bits));
}

Fixed::Fixed( const float value )
{
	PRINT("Float constructor called");
	raw = static_cast<int>(roundf(value * (1 << bits)));
}

Fixed::Fixed(const Fixed& other )
{
	PRINT("Copy constructor called");
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	PRINT("Copy assignment operator called");
	this->raw = other.getRawBits();
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
	return (raw);
}

/**
 * @brief Sets the raw value of the fixed-point number
 */
void	Fixed::setRawBits( int const raw)
{
	this->raw = raw;
}

/**
 * @brief Converts raw value to float based on fractional bits
 */
float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(getRawBits()) / (1 << bits));
}

/**
 * @brief Converts raw value to int based on fractional bits
 */
int		Fixed::toInt( void ) const
{
	return (static_cast<int>(getRawBits() / (1 << bits)));
}

std::ostream& operator<<( std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
