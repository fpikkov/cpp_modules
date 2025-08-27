#include "PmergeMe.hpp"
#include <list>

static std::string	args_to_string( int argc, char** argv );
static bool			vector_sort( const std::string& input );
static bool			list_sort( const std::string& input );

int main( int argc, char** argv )
{
	// Parsing
	std::string inputString;

	inputString = args_to_string(argc, argv);
	if (inputString.empty())
	{
		std::cerr << "Error: no integral arguments to parse" << std::endl;
		return (1);
	}

	// Process
	if (!vector_sort(inputString))
		return (1);
	if (!list_sort(inputString))
		return (1);

	return (0);
}

static bool	vector_sort( const std::string& input )
{
	try
	{
		PmergeMe<int, std::vector> pm(input);

		pm.printContainer("Before:");
		pm.launch();
		pm.printContainer("After:");
		pm.printTime("vector");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
	return (true);
}

static bool	list_sort( const std::string& input )
{
	try
	{
		PmergeMe<int, std::list> pm(input);

		pm.launch();
		pm.printTime("list");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
	return (true);
}

static std::string	args_to_string( int argc, char** argv )
{
	std::string	temp;

	for (int idx = 1; idx < argc; ++idx)
	{
		temp += ' ';
		temp += argv[idx];
	}

	return (temp);
}
