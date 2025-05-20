/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:32:10 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/16 16:32:12 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( const AMateria& other );
		AMateria&	operator=( const AMateria& other );
		virtual ~AMateria( void );

		std::string	const &	getType( void ) const; // Returns the materia type

		virtual	AMateria*	clone( void ) const = 0;
		virtual void		use( ICharacter& target );
};

#endif
