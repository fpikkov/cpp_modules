/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:24:45 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 16:06:24 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	botty("Charlie");
	DiamondTrap	shouty("Shouty");
	DiamondTrap	clap(botty);

	clap = shouty;

	clap.showStatus();
	clap.highFivesGuys();
	clap.whoAmI();
	clap.attack(botty.getName());
	botty.takeDamage(clap.getAttackDamage());
	clap.takeDamage(botty.getAttackDamage());
	clap.beRepaired(botty.getAttackDamage());
	clap.beRepaired(10);
	clap.guardGate();
	clap.beRepaired(__UINT32_MAX__);
	clap.highFivesGuys();
	clap.attack(botty.getName());
	clap.attack(botty.getName());
	clap.attack(botty.getName());
	clap.attack(botty.getName());
	clap.guardGate();
	clap.attack(botty.getName());
	clap.attack(botty.getName());
	clap.attack(botty.getName());
	clap.highFivesGuys();
	clap.takeDamage(12);
	clap.takeDamage(__UINT32_MAX__);
	clap.beRepaired(10);
	clap.takeDamage(12);
	clap.highFivesGuys();

	return (0);
}
