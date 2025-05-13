/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:31:09 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 17:39:36 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	PRINT(GREEN << "WrongAnimal default constructor called" << CLEAR);
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( const WrongAnimal& other )
{
	PRINT(GREEN << "WrongAnimal copy constructor called" << CLEAR);
	*this = other;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& other )
{
	PRINT(GREEN << "WrongAnimal copy assignment operator called" << CLEAR);

	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	PRINT(RED << "WrongAnimal destructor called" << CLEAR);
}

std::string	WrongAnimal::getType( void ) const
{
	return (_type);
}

void	WrongAnimal::setType( std::string type )
{
	this->_type = type;
}

void	WrongAnimal::makeSound( void ) const
{
	PRINT(CYAN << "**Definitely not animal noises**" << CLEAR);
}