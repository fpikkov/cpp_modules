/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:06:50 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/27 15:06:52 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	PRINT("Yuck! I think I stepped on a bug! Guess I got to \"de-bug\" the bottom of my shoe.")
}

void	Harl::info( void )
{
	PRINT("For your information this dilapitated building is cursed with infestations.")
}

void	Harl::warning( void )
{
	PRINT("Hold on! I'm warning you, my dad works for Nintendo so don't you dare condemn this building!")
}

void	Harl::error( void )
{
	PRINT("YOU ERR IN YOUR WAYS, BEGONE INSPECTOR!")
}

Harl::e_type	Harl::hash( std::string level )
{
	if (level.compare("debug") == 0) return (DEBUG);
	if (level.compare("info") == 0) return (INFO);
	if (level.compare("warning") == 0) return (WARNING);
	if (level.compare("error") == 0) return (ERROR);
	return (UNKNOWN);
}

void	Harl::complain( std::string level )
{
	e_type	type = Harl::hash(level);

	switch (type)
	{
	case DEBUG:
		function = &Harl::debug;
		break ;
	case INFO:
		function = &Harl::info;
		break ;
	case WARNING:
		function = &Harl::warning;
		break ;
	case ERROR:
		function = &Harl::error;
		break ;
	default:
		function = NULL;
		break ;
	}
	if (function)
		(this->*function)();
}
