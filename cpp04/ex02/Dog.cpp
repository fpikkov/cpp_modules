/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:13:10 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/15 13:33:53 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	PRINT(GREEN << "Dog default constructor called" << CLEAR);
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( const Dog& other ) : AAnimal( other )
{
	PRINT(GREEN << "Dog copy constructor called" << CLEAR);
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

Dog&	Dog::operator=( const Dog& other )
{
	PRINT(GREEN << "Dog copy assignment operator called" << CLEAR);
	if (this != &other)
	{
		if (this->_brain)
			delete (this->_brain);
		this->_brain = new Brain();
		this->_brain = new Brain(*other._brain);

		AAnimal::operator=(other);
	}
	return (*this);
}

Dog::~Dog( void )
{
	delete (_brain);
	PRINT(RED << "Dog destructor called" << CLEAR);
}

void	Dog::makeSound( void ) const
{
	PRINT("Woof!");
}

std::string	Dog::getIdea( unsigned int index ) const
{
	return (_brain->getIdea(index));
}

void	Dog::setIdea( unsigned int index , std::string thought )
{
	_brain->setIdea(index, thought);
}
