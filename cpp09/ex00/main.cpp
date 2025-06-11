#include "BitcoinExchange.hpp"

/**
	ADDITIONAL INFO:
	Handle leap days
	Handle days before BTC was created
 */

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
