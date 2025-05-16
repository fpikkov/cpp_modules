/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:39 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/15 13:33:56 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	PRINT(GREEN << "Cat default constructor called" << CLEAR);
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( const Cat& other ) : AAnimal( other )
{
	PRINT(GREEN << "Cat copy constructor called" << CLEAR);
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

Cat&	Cat::operator=( const Cat& other )
{
	PRINT(GREEN << "Cat copy assignment operator called" << CLEAR);
	if (this != &other)
	{
		if (this->_brain)
			delete (this->_brain);
		this->_brain = new Brain(*other._brain);

		AAnimal::operator=(other);
	}
	return (*this);
}

Cat::~Cat( void )
{
	delete (_brain);
	PRINT(RED << "Cat destructor called" << CLEAR);
}

void	Cat::makeSound( void ) const
{
	PRINT("Meow!");
}

std::string	Cat::getIdea( unsigned int index ) const
{
	return (_brain->getIdea(index));
}

void	Cat::setIdea( unsigned int index , std::string thought )
{
	_brain->setIdea(index, thought);
}
