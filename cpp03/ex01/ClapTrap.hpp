/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:24:34 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/08 15:24:36 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# define PRINT(str) std::cout << str << std::endl;

# include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap& other );
		ClapTrap&	operator=( const ClapTrap& other);
		~ClapTrap( void );

		void	attack( const std::string& target);
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

	protected:
		std::string		getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;

		void	setName( std::string name );
		void	setHitPoints( unsigned int hitPoints );
		void	setEnergyPoints( unsigned int energyPoints );
		void	setAttackDamage( unsigned int attackDamage );
};

#endif
