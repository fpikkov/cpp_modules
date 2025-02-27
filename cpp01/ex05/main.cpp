/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:47:27 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/21 13:47:28 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define SIZE 4

static std::string g_types[SIZE] =
{
	"debug",
	"info",
	"warning",
	"error"
};

int	main( void )
{
	Harl	harlie;
	Harl	hurrl;

	for (int i = 0; i < SIZE; i++)
		harlie.complain(g_types[i]);
	for (int i = SIZE - 1; i >= 0; i--)
		hurrl.complain(g_types[i]);

	harlie.complain("hamburger");
	hurrl.complain("handburger");

	return (0);
}
