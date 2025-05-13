/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:24:39 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 14:56:35 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors and destructors

ClapTrap::ClapTrap( void )
{
	PRINT(GREEN << "Default ClapTrap constructor called" << CLEAR);

	_name = "NULLtrap";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap( std::string name )
{
	PRINT(GREEN << "ClapTrap constructor called" << CLEAR);

	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
	PRINT(GREEN << "ClapTrap copy constructor called" << CLEAR);

	*this = other;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& other)
{
	PRINT(GREEN << "ClapTrap copy assignment operator called" << CLEAR);

	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	PRINT(RED << "ClapTrap destructor called" << CLEAR);
}

// Getters and setters

std::string		ClapTrap::getName( void ) const
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints( void ) const
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints( void ) const
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage( void ) const
{
	return (_attackDamage);
}

void	ClapTrap::setName( std::string name )
{
	_name = name;
}

void	ClapTrap::setHitPoints( unsigned int hitPoints )
{
	_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints( unsigned int energyPoints )
{
	_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage( unsigned int attackDamage )
{
	_attackDamage = attackDamage;
}

// Public methods

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
	if (amount > __UINT32_MAX__ - _hitPoints)
		amount = __UINT32_MAX__ - _hitPoints;

	PRINT( _name << " repairs itself for " << amount << " hitpoints.");
	_hitPoints += amount;
	--_energyPoints;
}
