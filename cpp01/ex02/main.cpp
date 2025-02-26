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

#include <iostream>
#include <iomanip>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define CLEAR "\033[0m"

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << GREEN << "------------ ADDRESSES ------------" << CLEAR << std::endl;
	std::cout << "The memory address of      " << CYAN << "string:    " << CLEAR << &string << std::endl;
	std::cout << "The memory address held by " << CYAN << "stringPTR: " << CLEAR << stringPTR << std::endl;
	std::cout << "The memory address held by " << CYAN << "stringREF: " << CLEAR << &stringREF << std::endl;

	std::cout << std::endl << GREEN << "------------  VALUES   ------------" << CLEAR << std::endl;
	std::cout << "The value stored in        " << CYAN << "string:    " << CLEAR << string << std::endl;
	std::cout << "The value pointed to by    " << CYAN << "stringPTR: " << CLEAR << *stringPTR << std::endl;
	std::cout << "The value pointed to by    " << CYAN << "stringREF: " << CLEAR << stringREF << std::endl;

	return (0);
}
