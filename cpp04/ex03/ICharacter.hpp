/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:42:50 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/16 16:42:51 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

// Provides an interface, no implementation (cpp) required
class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void	equip( AMateria* m ) = 0;
		virtual void	unequip( int idx ) = 0;
		virtual void	use( int idx, ICharacter& target ) = 0;
};

#endif
