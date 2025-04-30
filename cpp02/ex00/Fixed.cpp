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

Fixed::Fixed(const Fixed& other )
{
	PRINT("Copy constructor called");
	// copy
}

Fixed& Fixed::operator=(const Fixed& other)
{
	PRINT("Copy assignment operator called");
	// assignment
}

Fixed::~Fixed( void )
{
	PRINT("Destructor called");
	// destructor
}

int		Fixed::getRawBits( void ) const
{
	PRINT("getRawBits member function called");
	// returns the raw value of the fixed-point value
}

void	Fixed::setRawBits( int const raw)
{
	PRINT("setRawBits member function called");
	// sets the raw value of the fixed-point number
}
