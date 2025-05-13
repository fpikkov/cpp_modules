/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:39 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 17:24:09 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	PRINT(GREEN << "Cat default constructor called" << CLEAR);
	this->_type = "Cat";
}

Cat::Cat( const Cat& other ) : Animal( other )
{
	PRINT(GREEN << "Cat copy constructor called" << CLEAR);
	*this = other;
}

Cat&	Cat::operator=( const Cat& other )
{
	PRINT(GREEN << "Cat copy assignment operator called" << CLEAR);
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat( void )
{
	PRINT(RED << "Cat destructor called" << CLEAR);
}

void	Cat::makeSound( void ) const
{
	PRINT("Meow!");
}
