/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:46:07 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 15:28:00 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	PRINT(GREEN << "Default ScavTrap constructor called" << CLEAR);

	_guarding = false;
	setHitPoints(SCAV_HP);
	setEnergyPoints(SCAV_EP);
	setAttackDamage(SCAV_AD);
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	PRINT(GREEN << "ScavTrap constructor called" << CLEAR);

	_guarding = false;
	setHitPoints(SCAV_HP);
	setEnergyPoints(SCAV_EP);
	setAttackDamage(SCAV_AD);
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap( other )
{
	PRINT(GREEN << "ScavTrap copy constructor called" << CLEAR);

	this->_guarding = other._guarding;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& other )
{
	PRINT(GREEN << "ScavTrap copy assignment operator called" << CLEAR);

	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_guarding = other._guarding;
	}
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	PRINT(RED << "ScavTrap destructor called" << CLEAR);
}

void	ScavTrap::attack( const std::string& target )
{
	if (getHitPoints() == 0)
	{
		PRINT( getName() << " is dead");
		return ;
	}
	if (getEnergyPoints() == 0)
	{
		PRINT( getName() << " is too tired to fight");
		return ;
	}

	PRINT( "Guardian " << getName() << " slaps " << target << " and does " << getAttackDamage() << " points of damage!");
	setEnergyPoints(getEnergyPoints() - 1);
}

void	ScavTrap::guardGate( void )
{
	if (getEnergyPoints() == 0)
	{
		PRINT( getName() << " is too tired to guard the gate.");
		return ;
	}
	if (getHitPoints() == 0)
	{
		PRINT( getName() << " can not guard the gate from the afterlife.");
		return ;
	}
	if (!_guarding)
	{
		PRINT( getName() << " is now guarding the gate.");
	}
	else
	{
		PRINT( getName() << " is no longer guarding the gate.");
	}
	_guarding = !_guarding;
	setEnergyPoints(getEnergyPoints() - 1);
}

void	ScavTrap::defaultHitPoints( void )
{
	setHitPoints(SCAV_HP);
}

void	ScavTrap::defaultEnergyPoints( void )
{
	setEnergyPoints(SCAV_EP);
}

void	ScavTrap::defaultAttackDamage( void )
{
	setAttackDamage(SCAV_AD);
}
