/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:47:04 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/21 13:47:05 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# ifndef DEBUG
#  define DEBUG 0
# endif

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define CLEAR "\033[0m"

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	name;

	public:
				Zombie( std::string zombie_name );
				~Zombie( void );
		void	announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
