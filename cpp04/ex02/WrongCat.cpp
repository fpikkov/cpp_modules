/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:40:44 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 17:44:59 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	PRINT(GREEN << "WrongCat default constructor called" << CLEAR);
	this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal( other )
{
	PRINT(GREEN << "WrongCat copy constructor called" << CLEAR);
	*this = other;
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	PRINT(GREEN << "WrongCat copy assignment operator called" << CLEAR);
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat( void )
{
	PRINT(RED << "WrongCat destructor called" << CLEAR);
}

void	WrongCat::makeSound( void ) const
{
	PRINT("Mrreow!");
}