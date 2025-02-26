/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:09:25 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/06 18:09:27 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	while (true)
	{
		std::cout << std::setw(10) << "\033[33m[PHONEBOOK]\033[0m" << std::right << std::endl;
		std::getline(std::cin, input);
		std::cout << std::endl;
		for (int i = 0; input[i]; i++)
			input[i] = toupper(input[i]);
		if (input.compare("ADD") == 0)
			book.add();
		else if (input.compare("SEARCH") == 0)
			book.search();
		else if (input.compare("EXIT") == 0)
			break ;
		else
			std::cout << "The valid commands are: ADD, SEARCH, EXIT" << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
