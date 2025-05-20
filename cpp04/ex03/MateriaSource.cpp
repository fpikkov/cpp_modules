/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:15:53 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/20 17:15:54 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int idx = 0; idx < MATERIA_MAX; idx++)
		_materias[idx] = 0;
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
	*this = other;
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other )
{
	if (this != &other)
	{
		// Clear previous Materia
		for (int idx = 0; idx < MATERIA_MAX; idx++)
		{
			if (_materias[idx])
				delete (_materias[idx]);
			_materias[idx] = 0;
		}
		// Perform a deep copy
		for (int idx = 0; idx < MATERIA_MAX; idx++)
		{
			if (other._materias[idx])
				_materias[idx] = other._materias[idx]->clone();
		}
	}

	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	for (int idx = 0; idx < MATERIA_MAX; idx++)
	{
		if (_materias[idx])
			delete (_materias[idx]);
		_materias[idx] = 0;
	}
}

void	MateriaSource::learnMateria( AMateria* m )
{
	if (!m)
		return ;
	for (int idx = 0; idx < MATERIA_MAX; idx++)
	{
		if (!_materias[idx])
			_materias[idx] = m->clone();
	}
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for (int idx = MATERIA_MAX - 1; idx >= 0; idx--)
	{
		if (_materias[idx]->getType() == type)
		{
			return (_materias[idx]->clone());
		}
	}
	return (0);
}
