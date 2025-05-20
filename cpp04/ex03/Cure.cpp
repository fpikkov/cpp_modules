/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:20:40 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/20 13:20:41 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{

}

Cure::Cure( const Cure& other ) : AMateria("cure")
{

}

Cure&	Cure::operator=( const Cure& other )
{
	if (this != &other)
	{
		// Do nothing
	}
	return (*this);
}

Cure::~Cure( void )
{

}

AMateria*	Cure::clone( void ) const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
