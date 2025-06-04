#include "iter.hpp"

#define SIZE 7

int	main()
{
	int	arr[SIZE] = { -1, 0, 1, 2, 3, 4, 5};

	std::cout << "=== Printing original array ===" << std::endl;
	::iter(arr, SIZE, &print);
	std::cout << std::endl;

	std::cout << "=== Squaring array ===" << std::endl;
	::iter(arr, SIZE, &square);

	std::cout << "=== Printing adjusted array ===" << std::endl;
	::iter(arr, SIZE, &print);
	std::cout << std::endl;

	return (0);
}
