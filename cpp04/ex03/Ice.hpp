/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:47:47 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/20 12:47:48 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice( const Ice& other );
		Ice&	operator=( const Ice& other );
		~Ice( void );

		AMateria*	clone( void ) const;
		void		use( ICharacter& target );
};

#endif
