/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:32:15 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/16 16:32:16 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void )
{
	// _type is already empty
}

AMateria::AMateria( std::string const & type )
{
	_type = type;
}

AMateria::AMateria( const AMateria& other)
{
	*this = other;
}

AMateria&	AMateria::operator=( const AMateria& other )
{
	if (this != &other)
		_type = other.getType();
	return (*this);
}

AMateria::~AMateria( void )
{

}

std::string	const &	AMateria::getType( void ) const
{
	return (_type);
}

void	AMateria::use( ICharacter& target )
{
	(void)target;
	if (_type.empty())
		std::cerr << "AMateria type not set" << std::endl;
}
