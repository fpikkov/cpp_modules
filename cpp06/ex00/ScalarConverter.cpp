#include "ScalarConverter.hpp"

// Required method

void	ScalarConverter::convert( std::string literal )
{
	EType	type = findType(literal);

}

// Helper methods

// TODO: Rethink the implementation
ScalarConverter::EType	ScalarConverter::findType( std::string literal )
{
	if ((literal.length() == 1) && std::isalnum(literal[0]))
		return (CHAR);
	if (literal.length() > 0 &&
		((literal.find('.', 0) != std::string::npos && literal.find('f', 0) != std::string::npos)
		|| (literal.compare("-inff") == 0 || literal.compare("+inff") == 0 || literal.compare("nanf") == 0 )))
		return (FLOAT);
	if (literal.length() > 0 && (literal.find('.', 0) != std::string::npos)
		&& (literal.find('f', 0) == std::string::npos) )
		return (DOUBLE);
	if (literal.length() > 0 && (literal.find('.', 0) == std::string::npos)
		&& (literal.find('f', 0) == std::string::npos) )
		return (INTEGER);
	return (UNKNOWN);
}
