/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:21:50 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 17:23:30 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# define PRINT(str) std::cout << str << std::endl;

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define CLEAR "\033[0m"

# include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal( void );
		Animal( const Animal& other );
		Animal&	operator=( const Animal& other );
		virtual	~Animal( void );

		std::string	getType( void ) const;
		void		setType( std::string type );

		virtual void	makeSound( void ) const;
};

#endif