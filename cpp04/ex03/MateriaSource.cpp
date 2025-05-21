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

/**
 * Subject quotes: Copies the Materia passed as a parameter and store it in memory so it can be cloned later.
 * The main provided:
 * 		IMateriaSource* src = new MateriaSource();
 * 		src->learnMateria(new Ice());
 * 		src->learnMateria(new Cure());
 *
 * The two are contradicting as "copying" (creating clones) would lead to a memory leak with the provided main.
 */
void	MateriaSource::learnMateria( AMateria* m )
{
	if (!m)
		return ;
	for (int idx = 0; idx < MATERIA_MAX; idx++)
	{
		if (!_materias[idx])
		{
			_materias[idx] = m;
			return ;
		}
	}

	// Memory safety
	std::string	buffer;
	std::cout << "MateriaSource storage is full, would you like to delete the resource? y/n" << std::endl;
	std::getline(std::cin, buffer);
	if (!buffer.empty() && (buffer[0] == 'y' || buffer[0] == 'Y'))
		delete (m);
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for (int idx = MATERIA_MAX - 1; idx >= 0; idx--)
	{
		if (_materias[idx] && _materias[idx]->getType() == type)
		{
			return (_materias[idx]->clone());
		}
	}
	return (0);
}
