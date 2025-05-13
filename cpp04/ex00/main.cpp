/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:20:05 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 17:48:41 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal*	meta = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	const WrongAnimal*	wrong = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << wrong->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	wrong->makeSound();
	wrongCat->makeSound();

	delete wrong;
	delete wrongCat;

	return (0);
}
