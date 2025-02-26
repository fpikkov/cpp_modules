/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:14:18 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/24 15:14:19 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# ifndef DEBUG
#  define DEBUG 0
# endif

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define CLEAR "\033[0m"

# include <iostream>

class Weapon
{
	private:
		std::string	type;


	public:
							Weapon( void );
							Weapon( std::string new_type );
							~Weapon( void );
		const std::string&	getType( void );
		void				setType( std::string new_type );
};

#endif
