/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:03:34 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 15:35:13 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap& other );
		DiamondTrap&	operator=( const DiamondTrap& other );
		~DiamondTrap( void );

		void	attack( const std::string& target );
		void	whoAmI( void );

		void	showStatus( void );
};

#endif
