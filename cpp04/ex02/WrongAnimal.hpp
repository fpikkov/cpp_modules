/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:31:12 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 17:50:14 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# ifndef PRINT
#  define PRINT(str) std::cout << str << std::endl;
# endif

# ifndef RED
#  define RED "\033[1;31m"
# endif
# ifndef GREEN
#  define GREEN "\033[1;32m"
# endif
# ifndef CYAN
#  define CYAN "\033[1;36m"
# endif
# ifndef CLEAR
#  define CLEAR "\033[0m"
# endif

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal& other );
		WrongAnimal&	operator=( const WrongAnimal& other );
		virtual ~WrongAnimal( void );

		std::string	getType( void ) const;
		void		setType( std::string type );

		void	makeSound( void ) const;
};

#endif