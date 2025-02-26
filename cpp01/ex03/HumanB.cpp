/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:15:24 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/24 15:15:25 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->name = name;
	this->weapon = NULL;
	if (DEBUG)
		std::cout << "Human " << name << "was spawned" << std::endl;
}

HumanB::~HumanB( void )
{
	if (DEBUG)
		std::cout << "Human " << name << "was despawned" << std::endl;
}

void	HumanB::attack( void )
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " cannot attack without a weapon" << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	if (DEBUG)
		std::cout << name << " picks up " << weapon.getType() << std::endl;
	this->weapon = &weapon;
}

