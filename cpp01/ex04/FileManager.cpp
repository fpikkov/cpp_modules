/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:43:12 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/27 12:43:14 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManager.hpp"

FileManager::FileManager( char* file, char* s1, char* s2 )
{
	if (!file || !s1 || !s2)
	{
		error = MISSING_ARGS;
		return ;
	}
	else
		error = SUCCESS;
	filename = file;
	source = s1;
	target = s2;
}

FileManager::~FileManager( void )
{
	this->close();
}

e_errors	FileManager::checkError( void )
{
	return (error);
}

/**
 * @brief Replaces each match of "source" with "target" for each line read from the infile.
 */
void	FileManager::process( void )
{
	std::string	buffer;
	size_t		found;

	if (!infile || !outfile || source.empty())
		return (setError(MISSING_ARGS));
	do
	{
		std::getline(infile, buffer);
		if (!infile.eof() && !infile.fail())
			buffer.append("\n");
		do
		{
			found = buffer.find(source);
			if (found == std::string::npos)
				break ;
			buffer = buffer.substr(0, found) + target + buffer.substr(found + source.length());
			found += target.length();
		}
		while (found != std::string::npos);
		outfile << buffer;
	}
	while (!infile.eof());
}

void	FileManager::open( void )
{
	size_t	pos = std::string::npos;

	if (DEBUG)
		std::cout << "Opening files" << std::endl;
	if (filename.empty())
		return (setError(OPEN_FAILURE));
	infile.open(filename.c_str());
	if (!infile)
		return (setError(OPEN_FAILURE));
	pos = filename.find('.');
	if (pos != std::string::npos)
		filename = filename.substr(0, pos);
	filename.append(".replace");
	outfile.open(filename.c_str());
	if (!outfile)
	{
		infile.close();
		return (setError(OPEN_FAILURE));
	}
}

void	FileManager::close( void )
{
	if (DEBUG)
		std::cout << "Closing files" << std::endl;
	if (infile)
		infile.close();
	if (outfile)
		outfile.close();
}

void	FileManager::setError(e_errors value)
{
	this->error = value;
}

int	ft_error(e_errors error)
{
	switch (error)
	{
		case MISSING_ARGS:
			std::cerr << "Arguments required: <filename> <string_to_replace> <target_string>" << std::endl;
			break ;
		case OPEN_FAILURE:
			std::cerr << "Failed to open the given file" << std::endl;
			break ;
		default:
			break ;
	}
	return (0);
}
