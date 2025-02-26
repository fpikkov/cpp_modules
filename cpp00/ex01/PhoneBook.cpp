/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:33:37 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/06 18:33:38 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string g_responses[5] =
{
	"Uh-oh that index does not exist!",
	"Next time try a valid index.",
	"Oopsie-daisy, that was an invalid index!",
	"You should not be using a phonebook.",
	"ARE YOU STUPID???"
};

static void	guide(void)
{
	std::cout << std::setw(10) << "INDEX" << std::right;
	std::cout << " | ";
	std::cout << std::setw(10) << "FIRST NAME" << std::right;
	std::cout << " | ";
	std::cout << std::setw(10) << "LAST NAME" << std::right;
	std::cout << " | ";
	std::cout << std::setw(10) << "NICKNAME" << std::right;
	std::cout << std::endl;
}

PhoneBook::PhoneBook(void)
{
	last_index = 0;
	empty = true;
}

void	PhoneBook::add(void)
{
	if (last_index == 8)
		last_index = 0;
	contacts[last_index].input();
	last_index++;
	if (empty == true)
		empty = false;
}

void	PhoneBook::search(void)
{
	std::string	prompt;
	int			entry;

	std::cout << std::setw(10) << "\033[32m[SEARCH]\033[0m" << std::right << std::endl;
	if (empty == true)
	{
		std::cout << "No searchable entries exist." << std::endl;
		return ;
	}
	guide();
	for (int idx = 0; idx < 8; idx++)
		contacts[idx].output(idx);
	std::cout << std::endl << "Which entry would you like to view?" << std::endl;
	std::getline(std::cin, prompt);
	entry = std::atoi(prompt.c_str());
	if (entry == 0 && !(prompt[0] >= '0' && prompt[0] <= '9'))
		entry = -1;
	std::cout << std::endl;
	if (entry >= 0 && entry <= 7)
		contacts[entry].details();
	else
		std::cout << g_responses[rand() % 4] << std::endl;
}
