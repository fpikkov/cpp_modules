/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:21:50 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/13 17:23:30 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# define PRINT(str) std::cout << str << std::endl;

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define CLEAR "\033[0m"

# include <iostream>

// Technically a pure abstract class as it contains no concrete functions.
class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal( void );
		AAnimal( const AAnimal& other );
		AAnimal&	operator=( const AAnimal& other );
		virtual	~AAnimal( void );

		virtual void	makeSound( void ) const = 0;
};

#endif
