/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:29:46 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/20 13:29:47 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define ITEM_MAX 4
# define STORAGE_MAX 32

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[ITEM_MAX];
		AMateria*	_storage[STORAGE_MAX];

		void	clearInventory( void );
		void	clearStorage( void );

	public:
		Character( void );
		Character( std::string const & name );
		Character( const Character& other );
		Character&	operator=(const Character& other );
		~Character( void );

		std::string const & getName() const;
		void	equip( AMateria* m );
		void	unequip( int idx );
		void	use( int idx, ICharacter& target );

		void	emptyFloor( void );
};

#endif
