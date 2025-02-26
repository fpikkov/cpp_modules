/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:14:10 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/24 15:14:11 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{
	this->type = "nothing";
	if (DEBUG)
		std::cout << "Empty weapon created" << std::endl;
}

Weapon::Weapon( std::string new_type )
{
	this->type = new_type;
	if (DEBUG)
		std::cout << "Weapon created" << std::endl;
}

Weapon::~Weapon( void )
{
	if (DEBUG)
		std::cout << "Weapon destroyed" << std::endl;
	return ;
}

const std::string&	Weapon::getType( void )
{
	const std::string	&ref = this->type;
	return (ref);
}

void	Weapon::setType( std::string new_type )
{
	this->type = new_type;
}
