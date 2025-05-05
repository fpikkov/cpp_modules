/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:32:14 by fpikkov           #+#    #+#             */
/*   Updated: 2025/04/30 13:32:15 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

static void	test(void)
{
	Fixed		a;
	Fixed const	b( 10.25f );
	Fixed		c( 2 );

	PRINT(std::endl << "--- ADDITIONAL TESTS ---");
	PRINT("a = " << a.toFloat());
	PRINT("b = " << b.toFloat());
	PRINT("c = " << c.toFloat());

	PRINT(std::endl << "--- MIN/MAX ---");
	PRINT("max(a, b) = " << Fixed::max(a, b));
	PRINT("min(a, b) = " << Fixed::min(a, b));

	PRINT(std::endl << "--- ARITHMETIC ---");
	PRINT("b + c = " << b + c);
	PRINT("b - c = " << b - c);
	PRINT("b * c = " << b * c);
	PRINT("b / c = " << b / c);

	PRINT(std::endl << "--- COMPARISON ---");
	PRINT("a <= b : " << (a <= b ? "true" : "false"));
	PRINT("b == c : " << (b == c ? "true" : "false"));
	PRINT("c != b : " << (c != b ? "true" : "false"));
	PRINT("c >= a : " << (c >= a ? "true" : "false"));
}

static void	danger(void)
{
	Fixed a;
	Fixed b(0);

	PRINT(std::endl << "--- WELCOME TO THE DANGER ZONE ---");
	PRINT(a / b);
}

int	main(int argc, char **argv)
{
	(void)argv;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	if (argc > 1)
	{
		test();
		try
		{
			danger();
		}
		catch (const std::exception& e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
	}
	return (0);
}
