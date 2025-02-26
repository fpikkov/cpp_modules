/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:53 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/06 17:41:55 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	for (int arg = 1; arg < argc; arg++)
	{
		for (int i = 0; argv[arg][i]; i++)
		{
			if (argv[arg][i] >= 'a' && argv[arg][i] <= 'z')
				std::cout << (char)(argv[arg][i] - 32);
			else
				std::cout << argv[arg][i];
		}
		std::cout << ' ';
	}
	if (argc > 1)
		std::cout << std::endl;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
