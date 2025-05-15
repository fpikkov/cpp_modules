/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:37 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/14 16:27:01 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat( void );
		Cat( const Cat& other );
		Cat&	operator=( const Cat& other );
		~Cat( void );

		void	makeSound( void ) const;

		std::string	getIdea( unsigned int index ) const;
		void		setIdea( unsigned int index , std::string thought );
};

#endif