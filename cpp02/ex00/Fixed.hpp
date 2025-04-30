/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:32:34 by fpikkov           #+#    #+#             */
/*   Updated: 2025/04/30 13:32:35 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define PRINT(str) std::cout << str << std::endl;

class Fixed
{
	private:
		int					number;
		static const int	fractional_bits = 8;

	public:
		Fixed( void );
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
};

#endif

