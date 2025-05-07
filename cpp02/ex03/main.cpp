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

#include "Point.hpp"
#include <iostream>

#define BOOL_MSG(var) var == true ? "true" : "false";
#define PRINT(str) std::cout << str << std::endl;

int	main(void)
{
	Point	a(0.0f, 3.0f);
	Point	b(2.0f, 3.0f);
	Point	c1(2.0f, 5.0f);
	Point	c2(2.0f, 0.0f);
	Point	p1(1.5f, 3.5f);
	Point	p2(1.0f, 4.0f);

	std::string	result;

	result = BOOL_MSG(bsp(a, b, c1, p1));
	PRINT("Is p1 inside of triangle(a, b, c1) : " << result);

	result = BOOL_MSG(bsp(a, b, c2, p1));
	PRINT("Is p1 inside of triangle(a, b, c2) : " << result);

	result = BOOL_MSG(bsp(a, b, c1, p2));
	PRINT("Is p2 inside of triangle(a, b, c1) : " << result);

	result = BOOL_MSG(bsp(a, b, p2, p2));
	PRINT("Is p2 inside of triangle(a, b, p2) : " << result);

	return (0);
}
