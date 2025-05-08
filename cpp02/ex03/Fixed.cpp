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

// Constructors and destructors

Fixed::Fixed( void )
{
	raw = 0;
}

Fixed::Fixed( const int value )
{
	raw = static_cast<int>(value * (1 << bits));
}

Fixed::Fixed( const float value )
{
	raw = static_cast<int>(roundf(value * (1 << bits)));
}

Fixed::Fixed(const Fixed& other )
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->raw = other.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{

}

// Getter and setter methods

int		Fixed::getRawBits( void ) const
{
	return (raw);
}

void	Fixed::setRawBits( int const raw)
{
	this->raw = raw;
}

// Type conversions

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(getRawBits()) / (1 << bits));
}

int		Fixed::toInt( void ) const
{
	return (getRawBits() >> bits);
}

//	Comparison operators

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->raw > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->raw < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->raw >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->raw <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->raw == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->raw != other.getRawBits());
}

// Arithmetic operators

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}
Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}
Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	long	shift;

	shift = static_cast<long>(this->getRawBits() * other.getRawBits());
	result.setRawBits(static_cast<int>(shift >> bits));
	return (result);
}
Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	long	shift;

	if (other.getRawBits() == 0)
		throw (std::runtime_error("Division by zero"));

	shift = static_cast<long>(this->getRawBits() << bits);
	result.setRawBits(static_cast<int>(shift / other.getRawBits()));
	return (result);
}

// Increment and decrement operators

Fixed&	Fixed::operator++( void )
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	result;

	result.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() + 1);
	return (result);
}

Fixed&	Fixed::operator--( void )
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	result;

	result.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() - 1);
	return (result);
}

// Min and max methods

Fixed&	Fixed::min( Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max( Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

// Stdout operator

std::ostream& operator<<( std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
