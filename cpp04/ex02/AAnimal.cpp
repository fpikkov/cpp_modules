/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:21:54 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 17:23:46 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void )
{
	PRINT(GREEN << "AAnimal default constructor called" << CLEAR);
	this->_type = "AAnimal";
}

AAnimal::AAnimal( const AAnimal& other )
{
	PRINT(GREEN << "AAnimal copy constructor called" << CLEAR);
	*this = other;
}

AAnimal&	AAnimal::operator=( const AAnimal& other )
{
	PRINT(GREEN << "AAnimal copy assignment operator called" << CLEAR);

	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

AAnimal::~AAnimal( void )
{
	PRINT(RED << "AAnimal destructor called" << CLEAR);
}

void	AAnimal::makeSound( void ) const
{
	PRINT(CYAN << "**Random AAnimal noises**" << CLEAR);
}
