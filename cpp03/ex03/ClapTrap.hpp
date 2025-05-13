/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:24:34 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 15:17:20 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# define PRINT(str) std::cout << str << std::endl;

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define CLEAR "\033[0m"

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
		virtual ~ClapTrap( void );

		virtual void	attack( const std::string& target);
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

		std::string		getName( void ) const;
		unsigned int	getAttackDamage( void ) const;

	protected:
		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;

		void	setName( std::string name );
		void	setHitPoints( unsigned int hitPoints );
		void	setEnergyPoints( unsigned int energyPoints );
		void	setAttackDamage( unsigned int attackDamage );
};

#endif
