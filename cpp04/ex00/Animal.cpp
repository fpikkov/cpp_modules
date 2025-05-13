/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:21:54 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 17:23:46 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
	PRINT(GREEN << "Animal default constructor called" << CLEAR);
	this->_type = "Animal";
}

Animal::Animal( const Animal& other )
{
	PRINT(GREEN << "Animal copy constructor called" << CLEAR);
	*this = other;
}

Animal&	Animal::operator=( const Animal& other )
{
	PRINT(GREEN << "Animal copy assignment operator called" << CLEAR);

	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal( void )
{
	PRINT(RED << "Animal destructor called" << CLEAR);
}

std::string	Animal::getType( void ) const
{
	return (_type);
}

void	Animal::setType( std::string type )
{
	this->_type = type;
}

void	Animal::makeSound( void ) const
{
	PRINT(CYAN << "**Random animal noises**" << CLEAR);
}
