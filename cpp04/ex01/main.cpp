/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:20:05 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/15 13:31:11 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ARR_SIZE 6

static void	farm_animals(void)
{
	Animal*	farm[ARR_SIZE];

	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (i < ARR_SIZE / 2)
			farm[i] = new Cat();
		else
			farm[i] = new Dog();
	}

	for (int i = 0; i < ARR_SIZE; i++)
		delete (farm[i]);
}

static void	brain_surgery(void)
{
	Cat	mirri;

	mirri.setIdea(0, "He needs some milk");
	mirri.setIdea(1, "Mow");
	PRINT("Mirri's first idea: " << mirri.getIdea(0));
	PRINT("Cloning Mirri a cousin.");

	Cat musti(mirri);
	PRINT("Musti's first idea: " << musti.getIdea(0));
	PRINT("Musti gets a better idea.");
	musti.setIdea(0, "Cat-astrophy avoided!");
	PRINT("Mirri's first idea: " << mirri.getIdea(0));
	PRINT("Musti's first idea: " << musti.getIdea(0));
}

int	main(void)
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	delete dog; //should not create a leak
	delete cat;

	farm_animals();
	brain_surgery();

	return (0);
}
