#pragma once

#include <iostream>
#include <limits>
#include <string>

class ScalarConverter
{
	private:
		enum EType
		{
			CHAR = 0,
			INTEGER,
			FLOAT,
			DOUBLE,
			UNKNOWN
		};

		ScalarConverter() = delete;
		ScalarConverter( const ScalarConverter& other ) = delete;
		ScalarConverter&	operator=( const ScalarConverter& other ) = delete;
		~ScalarConverter() = delete;

		static EType	findType( std::string literal );

	public:
		static void	convert( std::string literal );
};
