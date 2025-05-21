/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:47:42 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/20 12:47:43 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{

}

// While assigning a Materia to another, copying the type doesn’t make sense.
Ice::Ice( const Ice& other ) : AMateria("ice")
{
	(void)other;
}

Ice&	Ice::operator=( const Ice& other )
{
	if (this != &other)
	{
		// Do nothing
	}
	return (*this);
}

Ice::~Ice( void )
{

}

AMateria*	Ice::clone( void ) const
{
	return (new Ice(*this));
}

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
