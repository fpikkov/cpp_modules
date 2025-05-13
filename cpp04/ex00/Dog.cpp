/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:13:10 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 17:24:11 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	PRINT(GREEN << "Dog default constructor called" << CLEAR);
	this->_type = "Dog";
}

Dog::Dog( const Dog& other ) : Animal( other )
{
	PRINT(GREEN << "Dog copy constructor called" << CLEAR);
	*this = other;
}

Dog&	Dog::operator=( const Dog& other )
{
	PRINT(GREEN << "Dog copy assignment operator called" << CLEAR);
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog( void )
{
	PRINT(RED << "Dog destructor called" << CLEAR);
}

void	Dog::makeSound( void ) const
{
	PRINT("Woof!");
}
