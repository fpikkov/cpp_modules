/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:20:45 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/20 13:20:46 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( const Cure& other );
		Cure&	operator=( const Cure& other );
		~Cure( void );

		AMateria*	clone( void ) const;
		void		use( ICharacter& target );
};

#endif
