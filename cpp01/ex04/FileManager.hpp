/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:43:05 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/27 12:43:07 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FILEMANAGER_HPP
# define FILEMANAGER_HPP

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <iostream>
# include <fstream>

enum e_errors
{
	SUCCESS = 0,
	MISSING_ARGS,
	OPEN_FAILURE,
};

class FileManager
{
	private:
		e_errors		error;
		std::ifstream	infile;
		std::ofstream	outfile;
		std::string		filename;
		std::string		source;
		std::string		target;

		void		setError(e_errors value);
	public:
		FileManager( char* file, char* s1, char* s2 );
		~FileManager( void );
		e_errors	checkError( void );
		void		open( void );
		void		process( void );
		void		close( void );

};

int	ft_error(e_errors error);

#endif
