/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:14:49 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/24 15:14:50 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon )
{
	this->name = name;
	this->weapon = weapon;
	if (DEBUG)
		std::cout << "Human " << name << "was spawned" << std::endl;
}

HumanA::~HumanA( void )
{
	if (DEBUG)
		std::cout << "Human " << name << "was despawned" << std::endl;
}

void	HumanA::attack( void )
{
	std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
}

void	HumanA::setWeapon( Weapon& weapon )
{
	if (DEBUG)
		std::cout << name << " picks up " << this->weapon.getType() << std::endl;
	this->weapon = weapon;
}
