/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:33:49 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/06 18:33:50 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static std::string	truncate(std::string str)
{
	std::string	trunc;

	if (str.length() > 10)
	{
		trunc = str.substr(0, 9);
		trunc.append(".");
		return (trunc);
	}
	return (str);
}

Contact::Contact(void)
{
	empty = true;
}

void	Contact::input(void)
{
	std::cout << std::setw(10) << "\033[32m[NEW CONTACT]\033[0m" << std::right << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, first_name);
	std::cout << "Last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, nick);
	std::cout << "Phone number: ";
	std::getline(std::cin, number);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);
	if (empty == true)
		empty = false;
}

void	Contact::output(int &index)
{
	if (empty == true)
		return ;
	std::cout << std::setw(10) << index << std::right;
	std::cout << " | ";
	std::cout << std::setw(10) << truncate(first_name) << std::right;
	std::cout << " | ";
	std::cout << std::setw(10) << truncate(last_name) << std::right;
	std::cout << " | ";
	std::cout << std::setw(10) << truncate(nick) << std::right;
	std::cout << std::endl;
}

void	Contact::details(void)
{
	if (empty == true)
	{
		std::cout << "You attempted to look up an empty field." << std::endl;
		return ;
	}
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nick << std::endl;
	std::cout << "Phone number: " << number << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}
