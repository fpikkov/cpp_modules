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

int	main( int argc, char **argv )
{
	std::string	input;
	Harl		harl;

	if (argc == 2)
	{
		input = argv[1];
		for (int i = 0; input[i]; i++)
			input[i] = tolower(input[i]);
	}
	else
		input = "random";
	harl.complain(input);
	return (0);
}
