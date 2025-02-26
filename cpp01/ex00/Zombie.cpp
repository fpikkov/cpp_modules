/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:47:10 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/21 13:47:11 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zombie_name)
{
	name = zombie_name;
	if (DEBUG)
		std::cout << name << ": was spawned" << std::endl;
	announce();
}

Zombie::~Zombie( void )
{
	std::cout << name << ": was killed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
