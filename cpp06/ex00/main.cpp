#include "ScalarConverter.hpp"

int	main( int argc, char** argv )
{
	std::string	literal;

	for (int i = 1; i < argc; ++i)
	{
		literal = argv[i];
		ScalarConverter::convert(literal);
	}

	return (0);
}
