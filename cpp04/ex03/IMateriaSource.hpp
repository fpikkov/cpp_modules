/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:56:34 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/20 16:56:35 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

// Provides an interface, no implementation (cpp) required
class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void		learnMateria( AMateria* ) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif
