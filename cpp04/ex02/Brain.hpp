/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:59:30 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/14 16:01:36 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# define BRAIN_SIZE 100

# include <iostream>

class Brain
{
	private:
		std::string	_ideas[BRAIN_SIZE];

	public:
		Brain( void );
		Brain( const Brain& other );
		Brain&	operator=( const Brain& other );
		~Brain( void );

		std::string	getIdea( unsigned int index ) const;
		void		setIdea( unsigned int index , std::string thought );
};

#endif