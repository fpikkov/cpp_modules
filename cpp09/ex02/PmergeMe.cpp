#include "PmergeMe.hpp"

std::string	args_to_string( int argc, char** argv )
{
	std::string	temp;

	for (int idx = 1; idx < argc; ++idx)
	{
		temp += ' ';
		temp += argv[idx];
	}

	return (temp);
}
