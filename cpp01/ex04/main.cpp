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

#include <iostream>
#include <fstream>
#include "replace.hpp"

int	ft_error(e_errors error)
{
	switch (error)
	{
		case MISSING_ARGS:
			std::cerr << "Arguments required: <filename> <string_to_replace> <target_string>" << std::endl;
			break;
		case OPEN_FAILURE:
			std::cerr << "Failed to open the given file" << std::endl;
			break;
		default:
			break;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		filename;
	std::string		buffer;
	std::string		s1;
	std::string		s2;

	if (argc < 4)
		return (ft_error(MISSING_ARGS));

	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	infile.open(filename);
	if (!infile)
		return (ft_error(OPEN_FAILURE));

	return (0);
}
