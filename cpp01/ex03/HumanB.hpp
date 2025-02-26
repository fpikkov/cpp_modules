/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:15:29 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/24 15:15:31 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		weapon;

	public:
				HumanB( std::string name );
				~HumanB( void );
		void	attack( void );
		void	setWeapon( Weapon& weapon );

};

#endif
