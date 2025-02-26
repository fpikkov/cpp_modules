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

#include "Zombie.hpp"

# define ARR_SIZE 5

static void hordeApproach(int size, Zombie *horde)
{
	std::cout << CYAN << "Announcing zombies in a different scope." << std::endl;
	if (!horde || size <= 0)
		return ;
	for (int i = 0; i < size; i++)
		horde[i].announce();
	std::cout << CLEAR;
}

int	main(void)
{
	std::string	name;
	std::string	empty;
	Zombie		*horde;

	name = "George";

	if (DEBUG)
		std::cout << GREEN << "Allocating on the heap" << CLEAR << std::endl;
	horde = zombieHorde(ARR_SIZE, name);
	hordeApproach(ARR_SIZE, horde);
	delete[] horde;
	if (DEBUG)
		std::cout << RED << "Heap allocated horde destroyed" << CLEAR << std::endl;
	horde = NULL;
	horde = zombieHorde(-1, name);
	if (!horde)
		std::cout << CYAN <<"Allocation failed due to invalid arguments." << CLEAR << std::endl;
	else
	{
		delete[] horde;
		horde = NULL;
	}
	horde = zombieHorde(1, empty);
	if (!horde)
		std::cout << CYAN <<"Allocation failed due to invalid arguments." << CLEAR << std::endl;
	else
	{
		delete[] horde;
		horde = NULL;
	}
	return (0);
}
