/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:07:13 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/27 15:07:14 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define PRINT(str) std::cout << str << std::endl;

class Harl
{
	private:
		enum e_type
		{
			UNKNOWN = 0,
			DEBUG,
			INFO,
			WARNING,
			ERROR,
		};
		void	(Harl::*function)();

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		e_type	hash( std::string level );

	public:
		void	complain( std::string level );

};

#endif
