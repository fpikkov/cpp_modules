/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:59:28 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/14 21:39:13 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "\033[1;32m" << "Brain default constructor called" << "\033[0m" << std::endl;
}

Brain::Brain( const Brain& other )
{
	std::cout << "\033[1;32m" << "Brain copy constructor called" << "\033[0m" << std::endl;
	*this = other;
}

Brain&	Brain::operator=( const Brain& other )
{
	std::cout << "\033[1;32m" << "Brain copy assignment operator called" << "\033[0m" << std::endl;
	if (this != &other)
	{
		for (int idx = 0; idx < BRAIN_SIZE; ++idx)
			this->_ideas[idx] = other._ideas[idx];
	}
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << "\033[1;31m" << "Brain destructor called" << "\033[0m" << std::endl;
}

std::string	Brain::getIdea( unsigned int index ) const
{
	if (index >= BRAIN_SIZE)
	{
		std::cout << "Brain too smål! Can't hold this many thoughts. ;(" << std::endl;
		return (0);
	}
	if (_ideas[index].empty())
		return ("Head empty, no thoughts.");
	return (_ideas[index]);
}

void	Brain::setIdea( unsigned int index , std::string thought )
{
	if (index >= BRAIN_SIZE)
	{
		std::cout << "Brain too smål! Can't hold this many thoughts. ;(" << std::endl;
		return ;
	}
	_ideas[index] = thought;
}