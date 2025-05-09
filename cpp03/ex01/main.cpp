/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:24:45 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/08 15:24:47 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	botty("Botty");
	ScavTrap	shouty("Shouty");
	ScavTrap	clap(botty);

	clap = shouty;
	std::string	bot = "Charlie";

	clap.guardGate();
	clap.attack(bot);
	clap.takeDamage(9);
	clap.beRepaired(9);
	clap.beRepaired(10);
	clap.beRepaired(10);
	clap.guardGate();
	clap.attack(bot);
	clap.attack(bot);
	clap.attack(bot);
	clap.attack(bot);
	clap.attack(bot);
	clap.attack(bot);
	clap.attack(bot);
	clap.guardGate();
	clap.takeDamage(12);
	clap.takeDamage(__UINT32_MAX__);
	clap.beRepaired(10);
	clap.takeDamage(12);
	clap.guardGate();

	return (0);
}
