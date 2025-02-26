/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:14:55 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/24 15:14:58 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		weapon;

	public:
				HumanA( std::string name, Weapon& weapon );
				~HumanA( void );
		void	attack( void );
		void	setWeapon( Weapon& weapon );

};

#endif
