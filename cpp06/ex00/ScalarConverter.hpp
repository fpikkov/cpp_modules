#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter( const ScalarConverter& other ) = delete;
		ScalarConverter&	operator=( const ScalarConverter& other ) = delete;
		~ScalarConverter() = delete;

	public:
		static void	convert( std::string literal );
};

enum EType
{
	CHAR = 0,
	INTEGER,
	FLOAT,
	DOUBLE,
	UNKNOWN
};
