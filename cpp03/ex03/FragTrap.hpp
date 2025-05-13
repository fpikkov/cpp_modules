/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:16:29 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 15:19:05 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAG_HP_EP 100
# define FRAG_AD 30

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap& other );
		FragTrap&	operator=( const FragTrap& other);
		~FragTrap( void );

		void	highFivesGuys(void);

	protected:
		void	defaultHitPoints( void );
		void	defaultEnergyPoints( void );
		void	defaultAttackDamage( void );
};

#endif
