#include "BitcoinExchange.hpp"

int main( int argc, char** argv )
{
	if (argc < 2)
	{
		std::cerr << "Error: missing input file" << std::endl;
		return (1);
	}

	BitcoinExchange	exchange(argv[1]);

	return (0);
}
