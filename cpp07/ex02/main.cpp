#include "Array.hpp"
#include <iostream>

int	main()
{
	std::cout << "\033[32;1m === Basic tests === \033[0m" << std::endl;
	try
	{
		Array<int>	empty;
		std::cout << empty[6] << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	try
	{
		Array<std::string>	not_empty(5);
		std::cout << "not_empty size: " << not_empty.size() << std::endl;

		not_empty[0] = "Hello";
		not_empty[1] = ",";
		not_empty[2] = " ";
		not_empty[3] = "World";
		not_empty[4] = "!";

		std::cout << not_empty[0] << not_empty[1] <<not_empty[2] << not_empty[3] << not_empty[4] << std::endl;
		not_empty[5] = "This is the end.";
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	std::cout << "\033[32;1m === Asssignment test === \033[0m" << std::endl;
	try
	{
		Array<std::string>	str1(2);
		Array<std::string>	str2(0);

		str1[0] = "What is the answer to life, the universe, and everything?";
		std::cout << "str1 size: " << str1.size() << std::endl;
		std::cout << "str2 size: " << str2.size() << std::endl;
		std::cout << "assigning str1 to str2" << std::endl;
		str2 = str1; // Assignment operator
		std::cout << "str1 size: " << str1.size() << std::endl;
		std::cout << "str2 size: " << str2.size() << std::endl;

		for (unsigned int idx = 0; idx < 2; ++idx)
			std::cout << "str1[" << idx << "]: " << str1[idx] << std::endl;
		for (unsigned int idx = 0; idx < 2; ++idx)
			std::cout << "str2[" << idx << "]: " << str2[idx] << std::endl;

		std::cout << "str2[1] = \"42\"" << std::endl;
		str2[1] = "42";
		for (unsigned int idx = 0; idx < 2; ++idx)
			std::cout << "str1[" << idx << "]: " << str1[idx] << std::endl;
		for (unsigned int idx = 0; idx < 2; ++idx)
			std::cout << "str2[" << idx << "]: " << str2[idx] << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	return (0);
}
