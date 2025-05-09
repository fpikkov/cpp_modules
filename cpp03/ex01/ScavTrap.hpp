/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:46:03 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/09 11:46:04 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_guarding;

	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& other );
		ScavTrap&	operator=( const ScavTrap& other);
		~ScavTrap( void );

		void	guardGate( void );
};

#endif
