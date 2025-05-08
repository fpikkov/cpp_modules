/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:24:39 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/08 15:24:40 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	PRINT("Default constructor called");

	_name = "NULLtrap";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap( std::string name )
{
	PRINT("Constructor called");

	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
	PRINT("Copy constructor called");

	*this = other;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& other)
{
	PRINT("Copy assignment operator called");

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	PRINT("Destructor called");
}

void	ClapTrap::attack( const std::string& target)
{
	if (_hitPoints == 0)
	{
		PRINT( _name << " is dead");
		return ;
	}
	if (_energyPoints == 0)
	{
		PRINT( _name << " is too tired to fight");
		return ;
	}

	PRINT( _name << " claps " << target << " and does " << _attackDamage << " points of damage!");
	--_energyPoints;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if ( amount > _hitPoints)
		amount = _hitPoints;
	if (_hitPoints == 0)
	{
		PRINT( _name << " can not be more dead than they already are.");
		return ;
	}

	PRINT( _name << " takes " << amount << " points of damage!");
	_hitPoints -= amount;
	if (_hitPoints == 0)
		PRINT( _name << " died!");
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_hitPoints == 0)
	{
		PRINT( _name << " could not resurrect itself.");
		return ;
	}
	if (_energyPoints == 0)
	{
		PRINT( _name << " is too tired to repair itself.");
		return ;
	}

	PRINT( _name << " repairs itself for " << amount << " hitpoints.");
}
