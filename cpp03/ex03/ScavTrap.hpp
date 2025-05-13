/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:46:03 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 15:27:11 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAV_HP 100
# define SCAV_EP 50
# define SCAV_AD 20

class ScavTrap : virtual public ClapTrap
{
	private:
		bool	_guarding;

	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& other );
		ScavTrap&	operator=( const ScavTrap& other);
		virtual	~ScavTrap( void );

		void	attack( const std::string& target);
		void	guardGate( void );

	protected:
		void	defaultHitPoints( void );
		void	defaultEnergyPoints( void );
		void	defaultAttackDamage( void );
};

#endif
