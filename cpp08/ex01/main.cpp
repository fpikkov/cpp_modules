#include "Span.hpp"

#include <iostream>
#include <random>

#define TEST_SIZE 20000

int	main()
{
	// Random number generator
	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<>	distrib(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

	// Span with RNG
	try
	{
		Span sp = Span(TEST_SIZE);

		for (size_t idx = 0; idx < TEST_SIZE; ++idx)
			sp.addNumber(distrib(gen));

		std::cout << "\033[32;1m=== Random Span ===\033[0m" << std::endl;
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	// Span with fixed numbers
	try
	{
		Span sp = Span(TEST_SIZE);

		for (size_t idx = 0; idx < TEST_SIZE; ++idx)
			sp.addNumber(static_cast<int>(idx));

		std::cout << "\033[32;1m=== Fixed Span ===\033[0m" << std::endl;
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	// Span accepting an array of numbers
	try
	{
		int	arr[] = { -10000, 0, 10000, 20000, 30000, 40000, 50000 };
		Span sp(TEST_SIZE);

		sp.addNumbers(arr);

		std::cout << "\033[32;1m=== Adding numbers in a single call ===\033[0m" << std::endl;
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	// Span from the subject's example
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "\033[32;1m=== Original test ===\033[0m" << std::endl;
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	// Out of range test
	try
	{
		Span sp = Span(5);

		std::cout << "\033[32;1m=== Out of range test ===\033[0m" << std::endl;

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.addNumber(11);

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	// Testing with invalid amount of numbers
	try
	{
		Span sp = Span(5);

		std::cout << "\033[32;1m=== Span unavailable ===\033[0m" << std::endl;

		sp.addNumber(6);

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	return (0);
}
