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

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap;
	std::string	bot = "Charlie";

	clap.attack(bot);
	clap.takeDamage(9);
	clap.beRepaired(9);
	clap.beRepaired(10);
	clap.beRepaired(10);
	clap.attack(bot);
	clap.attack(bot);
	clap.attack(bot);
	clap.attack(bot);
	clap.attack(bot);
	clap.attack(bot);
	clap.attack(bot);
	clap.takeDamage(12);
	clap.takeDamage(12);
	clap.beRepaired(10);
	clap.takeDamage(12);

	return (0);
}
