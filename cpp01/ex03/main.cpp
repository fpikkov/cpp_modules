/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:47:27 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/21 13:47:28 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		if (DEBUG)
			std::cout << GREEN << "Creating Bob with crude spiked club" << CLEAR << std::endl;
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("flawless riveted club");
		bob.attack();
	}
	{
		if (DEBUG)
			std::cout << GREEN << "Creating Jim without a weapon" << CLEAR << std::endl;
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("shoddy insignificant club");
		jim.attack();
	}
	{
		if (DEBUG)
			std::cout << GREEN << "Creating JimBob without a weapon" << CLEAR << std::endl;
		HumanB	jimbob("JimBob");
		jimbob.attack();

		Weapon	club = Weapon("crude spiked club");
		jimbob.setWeapon(club);
		jimbob.attack();

		Weapon spoon = Weapon("dull rusty spoon");
		jimbob.setWeapon(spoon);
		jimbob.attack();
	}
	return (0);
}
