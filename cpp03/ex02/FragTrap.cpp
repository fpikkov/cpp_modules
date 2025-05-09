/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:16:24 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/09 16:16:26 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define FIVES_MAX 5

static std::string g_fives[FIVES_MAX] = {
	" hands out high fives like it's Christmas.",
	" spins around and high fives everyone in their vicinity.",
	" gives a low then a high five.",
	" high fives followed by a ~smooth~ fistbump."
};

FragTrap::FragTrap( void ) : ClapTrap()
{
	PRINT("Default FragTrap constructor called");

	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	PRINT("FragTrap constructor called");

	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other)
{
	PRINT("FragTrap copy constructor called");
}

FragTrap&	FragTrap::operator=( const FragTrap& other)
{
	PRINT("FragTrap copy assignment operator called");

	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap( void )
{
	PRINT("FragTrap destructor called");
}

void	FragTrap::highFivesGuys(void)
{
	static int	counter = 0;

	if (getHitPoints() == 0)
	{
		PRINT( getName() << " has been disconnected.");
		return ;
	}
	if (getEnergyPoints() == 0)
	{
		PRINT( getName() << " is too tired to hand out high fives.");
		return ;
	}
	PRINT( getName() << g_fives[counter]);
	counter++;
	if (counter == FIVES_MAX - 1)
		counter = 0;
	setEnergyPoints(getEnergyPoints() - 1);
}
