/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:46:07 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/09 11:46:08 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	PRINT("Default ScavTrap constructor called");

	_guarding = false;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	PRINT("ScavTrap constructor called");

	_guarding = false;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other)
{
	PRINT("ScavTrap copy constructor called");

	this->_guarding = other._guarding;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& other)
{
	PRINT("ScavTrap copy assignment operator called");

	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_guarding = other._guarding;
	}
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	PRINT("ScavTrap destructor called");
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
