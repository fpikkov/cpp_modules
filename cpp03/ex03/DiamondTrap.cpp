/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:04:34 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 15:37:29 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap()
{
	PRINT(GREEN << "Default DiamondTrap constructor called" << CLEAR);
	this->_name = "DiamondBot";
	setName(this->_name + "_clap_name");
	FragTrap::defaultHitPoints();
	ScavTrap::defaultEnergyPoints();
	FragTrap::defaultAttackDamage();
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name" )
{
	PRINT(GREEN << "DiamondTrap constructor called" << CLEAR);
	this->_name = name;
	FragTrap::defaultHitPoints();
	ScavTrap::defaultEnergyPoints();
	FragTrap::defaultAttackDamage();
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap( other ), ScavTrap( other ), FragTrap( other )
{
	PRINT(GREEN << "DiamondTrap copy constructor called" << CLEAR);
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& other )
{
	PRINT(GREEN << "DiamondTrap copy assignment operator called" << CLEAR);
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	PRINT(RED << "DiamondTrap destructor called" << CLEAR);
}

void	DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	if (getHitPoints() == 0)
	{
		PRINT( "*ERROR MISSING RECORDS*" );
		return ;
	}
	if (getEnergyPoints() == 0)
	{
		PRINT( getName() << " lacks the energy to retrieve records.");
		return ;
	}
	PRINT( "I am " << this->_name << " of the " << getName() << " dynasty." );
	setEnergyPoints(getEnergyPoints() - 1);
}

void	DiamondTrap::showStatus( void )
{
	PRINT(CYAN << this->_name << " status report:" << CLEAR);
	PRINT(CYAN << "HP: " << getHitPoints() << CLEAR);
	PRINT(CYAN << "EP: " << getEnergyPoints() << CLEAR);
	PRINT(CYAN << "DPS: " << getAttackDamage() << CLEAR);
}
