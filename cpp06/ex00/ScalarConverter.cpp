#include "ScalarConverter.hpp"

// Helper functions

static bool	isChar( std::string literal )
{
	return ((literal.length() == 1) && std::isalpha(literal[0]));
}

static bool	isInt( std::string literal )
{
	if (literal.empty() || literal.find('.') != std::string::npos)
		return (false);

	size_t idx = 0;
	if (literal[idx] == '+' || literal[idx] == '-')
		++idx;
	for (; idx < literal.length(); ++idx)
	{
		if (!std::isdigit(literal[idx]))
			return (false);
	}
	try
	{
		std::stoi(literal);
		return (true);
	}
	catch(const std::exception& e) {}
	return (false);
}

static bool	isFloat( std::string literal )
{
	bool point_found = false;

	// Check pseudo-literals
	if ( !literal.compare("-inff") || !literal.compare("+inff") || !literal.compare("nanf") )
		return (true);

	size_t idx = 0;
	if (literal[idx] == '+' || literal[idx] == '-')
		++idx;
	for (; idx < literal.length() - 1; ++idx)
	{
		if (literal[idx] == '.')
		{
			if (point_found)
				return (false);
			point_found = true;
		}
		else if (!std::isdigit(literal[idx]))
			return (false);
	}
	try
	{
		std::stof(literal);
		return (true);
	}
	catch(const std::exception& e) {}
	return (false);
}

static bool	isDouble( std::string literal )
{
	bool point_found = false;

	// Check pseudo-literals
	if ( !literal.compare("-inf") || !literal.compare("+inf") || !literal.compare("nan") )
		return (true);

	// Check string format
	size_t idx = 0;
	if (literal[idx] == '+' || literal[idx] == '-')
		++idx;
	for (; idx < literal.length(); ++idx)
	{
		if (literal[idx] == '.')
		{
			if (point_found)
				return (false);
			point_found = true;
		}
		else if (!std::isdigit(literal[idx]))
			return (false);
	}
	try
	{
		std::stod(literal);
		return (true);
	}
	catch(const std::exception& e) {}
	return (false);
}

static EType	findType( std::string literal )
{
	if (isChar(literal))
		return (CHAR);
	else if (isInt(literal))
		return (INTEGER);
	else if (isFloat(literal))
		return (FLOAT);
	else if (isDouble(literal))
		return (DOUBLE);
	return (UNKNOWN);
}

static float	convertFloat( std::string literal )
{
	if (!literal.compare("-inff"))
		return (-std::numeric_limits<float>::infinity());
	else if (!literal.compare("+inff"))
		return (std::numeric_limits<float>::infinity());
	else if (!literal.compare("nanf"))
		return (std::numeric_limits<float>::quiet_NaN());
	return (std::stof(literal));
}

static double	convertDouble( std::string literal )
{
	if (!literal.compare("-inf"))
		return (-std::numeric_limits<double>::infinity());
	else if (!literal.compare("+inf"))
		return (std::numeric_limits<double>::infinity());
	else if (!literal.compare("nan"))
		return (std::numeric_limits<double>::quiet_NaN());
	return (std::stod(literal));
}

// Required method

void	ScalarConverter::convert( std::string literal )
{
	EType	type = findType(literal);

	bool	success = true;
	bool	char_impossible = false;
	bool	int_impossible = false;

	char	c = 0;
	int		i = 0;
	float	f = 0.0f;
	double	d = 0.0;

	switch (type)
	{
	case CHAR:
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		break ;
	case INTEGER:
		i = std::stoi(literal);
		if (i >= 0 && i <= 127)
			c = static_cast<char>(i);
		else
			char_impossible = true;
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		break ;
	case FLOAT:
		f = convertFloat(literal);
		if (!std::isnan(f) && std::isfinite(f) && (f >= 0.0f && f < 128.0f))
			c = static_cast<char>(f);
		else
			char_impossible = true;
		if (!std::isnan(f) && std::isfinite(f) \
			&& (f >= static_cast<float>(std::numeric_limits<int>::min()) \
			&& f <= static_cast<float>(std::numeric_limits<int>::max())))
			i = static_cast<int>(f);
		else
			int_impossible = true;
		d = static_cast<double>(f);
		break ;
	case DOUBLE:
		d = convertDouble(literal);
		if (!std::isnan(d) && std::isfinite(d) && (d >= 0.0 && d < 128.0))
			c = static_cast<char>(f);
		else
			char_impossible = true;
		if (!std::isnan(d) && std::isfinite(d) \
			&& (d >= static_cast<double>(std::numeric_limits<int>::min()) \
			&& d <= static_cast<double>(std::numeric_limits<int>::max())))
			i = static_cast<int>(f);
		else
			int_impossible = true;
		f = static_cast<float>(d);
		break ;
	default:
		success = false;
		break;
	}

	// Printing char
	if (char_impossible || !success)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	// Printiing int
	if (int_impossible || !success)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	// Printing float
	if (!success)
		std::cout << "float: impossiblle" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(0);
	}

	// Printing double
	if (!success)
		std::cout << "double: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << d << std::endl;
		std::cout << std::fixed << std::setprecision(0);
	}

}
