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

static std::string	names[ARR_SIZE] = {
	"John the Hungry",
	"Mike the Lipsmacker",
	"Quentin the Carnivore",
	"Sarah the Slurper",
	"Poe the Muncher"
};

int	main(void)
{
	// --- Stack allocation ---
	if (DEBUG)
		std::cout << GREEN << "Allocating on the stack" << CLEAR << std::endl;
	{
		for (int i = 0; i < ARR_SIZE; i++)
			Zombie zomb(names[i]);
	}
	if (DEBUG)
		std::cout << RED << "Stack allocated zombies destroyed" << CLEAR << std::endl;

	// --- Heap allocation ---
	if (DEBUG)
		std::cout << GREEN << "Allocating on the heap" << CLEAR << std::endl;
	Zombie	*zombies[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++)
		zombies[i] = newZombie(names[i]);
	{
		std::cout << CYAN << "In different scope the last zombie announces itself." << std::endl;
		zombies[ARR_SIZE - 1]->announce();
		std::cout << CLEAR;
	}
	for (int i = 0; i < ARR_SIZE; i++)
		delete zombies[i];
	if (DEBUG)
		std::cout << RED << "Heap allocated zombies destroyed" << CLEAR << std::endl;

	// -- The champs of chumps ---
	if (DEBUG)
		std::cout << GREEN << "Generating chumps" << CLEAR << std::endl;
	for (int i = 0; i < ARR_SIZE; i++)
		randomChump(names[i]);
	if (DEBUG)
		std::cout << RED << "Degenerated chumps" << CLEAR << std::endl;
	return (0);
}
