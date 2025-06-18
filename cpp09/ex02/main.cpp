#include "PmergeMe.hpp"
#include <list>

static auto	vector_sort( std::string inputString ) -> bool;
static auto	list_sort( std::string inputString ) -> bool;

int main( int argc, char** argv )
{
	// Parsing
	std::string	inputString;

	inputString = ft::args_to_string(argc, argv);
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

static auto	vector_sort( std::string inputString ) -> bool
{
	// Parsing
	std::vector<int>	inputValues;

	try
	{
		ft::string_to_container<int>(inputString, inputValues);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
	if (inputValues.empty())
	{
		std::cerr << "Error: failed to parse values" << std::endl;
		return (false);
	}

	// Sorting
	PmergeMe<int, std::vector<int>>	pm(inputValues);

	// TODO: a lot
	pm.printInfo();

	return (true);
}

static auto	list_sort( std::string inputString ) -> bool
{
	// Parsing
	std::list<int>	inputValues;

	try
	{
		ft::string_to_container<int>(inputString, inputValues);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (false);
	}
	if (inputValues.empty())
	{
		std::cerr << "Error: failed to parse values" << std::endl;
		return (false);
	}

	// Sorting
	PmergeMe<int, std::list<int>>	pm(inputValues);

	// TODO: a lot
	pm.printInfo();

	return (true);
}