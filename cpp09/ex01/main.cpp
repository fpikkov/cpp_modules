#include "RPN.hpp"

int main( int argc, char** argv )
{
	RPN	rpn;
	int	result = 0;

	for (int i = 1; i < argc; ++i)
	{
		try
		{
			result = rpn.launchRPN(argv[i]);
			std::cout << result << std::endl;
		}
		catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
	}

	return (0);
}
