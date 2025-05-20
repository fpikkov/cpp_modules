/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:15:57 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/20 17:15:59 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

# define MATERIA_MAX 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materias[MATERIA_MAX];

	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource& other );
		MateriaSource&	operator=( const MateriaSource& other );
		~MateriaSource( void );

		void		learnMateria( AMateria* m );
		AMateria*	createMateria( std::string const & type );
};

#endif
