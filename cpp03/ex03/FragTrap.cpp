/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:16:24 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 15:18:56 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <cstdlib>

#define FIVES_MAX 5

static std::string g_fives[FIVES_MAX] = {
	" hands out high fives like it's Christmas.",
	" spins around and high fives everyone in their vicinity.",
	" gives a low then a high five.",
	" high fives followed by a ~smooth~ fistbump."
};

FragTrap::FragTrap( void ) : ClapTrap()
{
	PRINT(GREEN << "Default FragTrap constructor called" << CLEAR);

	setHitPoints(FRAG_HP_EP);
	setEnergyPoints(FRAG_HP_EP);
	setAttackDamage(FRAG_AD);
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	PRINT(GREEN << "FragTrap constructor called" << CLEAR);

	setHitPoints(FRAG_HP_EP);
	setEnergyPoints(FRAG_HP_EP);
	setAttackDamage(FRAG_AD);
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other)
{
	PRINT(GREEN << "FragTrap copy constructor called" << CLEAR);
}

FragTrap&	FragTrap::operator=( const FragTrap& other)
{
	PRINT(GREEN << "FragTrap copy assignment operator called" << CLEAR);

	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap( void )
{
	PRINT(RED << "FragTrap destructor called" << CLEAR);
}

void	FragTrap::highFivesGuys(void)
{
	static bool	randomized = false;

	if (randomized == false)
	{
		std::srand(time(0));
		randomized = true;
	}
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
	PRINT( getName() << g_fives[std::rand() % (FIVES_MAX - 1)]);
	setEnergyPoints(getEnergyPoints() - 1);
}

void	FragTrap::defaultHitPoints( void )
{
	setHitPoints(FRAG_HP_EP);
}

void	FragTrap::defaultEnergyPoints( void )
{
	setEnergyPoints(FRAG_HP_EP);
}

void	FragTrap::defaultAttackDamage( void )
{
	setAttackDamage(FRAG_AD);
}
