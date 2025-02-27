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

#include "FileManager.hpp"

int	main(int argc, char **argv)
{
	if (argc < 4)
		return (ft_error(MISSING_ARGS));

	FileManager	handler(argv[1], argv[2], argv[3]);

	handler.open();
	if (handler.checkError())
		return (ft_error(handler.checkError()));
	handler.process();
	if (handler.checkError())
		return (ft_error(handler.checkError()));
	handler.close();

	return (0);
}
