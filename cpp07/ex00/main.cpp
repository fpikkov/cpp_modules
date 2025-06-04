#include "whatever.hpp"

#include <iostream>

struct Values{
	int				i1 = 0;
	int				i2 = 10;
	int const		ic1 = 100000;
	int const		ic2 = -800;
	float			f1 = 0.990f;
	float			f2 = 109.091f;
	std::string		s1 = "Hello";
	std::string		s2 = "world";
};

int	main()
{
	Values	val;

	std::cout << "=== Swapping integers ===" << std::endl;
	std::cout << "Pre-swap: i1 = " << val.i1 << ", i2 = " << val.i2 << std::endl;
	::swap(&val.i1, &val.i2);
	std::cout << "Post-swap: i1 = " << val.i1 << ", i2 = " << val.i2 << std::endl;
	std::cout << "Minimum = " << ::min(val.i1, val.i2) << std::endl;
	std::cout << "Maximum = " << ::max(val.i1, val.i2) << std::endl;
	std::cout << std::endl;


	std::cout << "=== Swapping floats ===" << std::endl;
	std::cout << "Pre-swap: f1 = " << val.f1 << ", f2 = " << val.f2 << std::endl;
	::swap(val.f1, val.f2);
	std::cout << "Post-swap: f1 = " << val.f1 << ", f2 = " << val.f2 << std::endl;
	std::cout << "Minimum = " << ::min(val.f1, val.f2) << std::endl;
	std::cout << "Maximum = " << ::max(val.f1, val.f2) << std::endl;
	std::cout << std::endl;

	std::cout << "=== Swapping strings ===" << std::endl;
	std::cout << "Pre-swap: s1 = " << val.s1 << ", s2 = " << val.s2 << std::endl;
	::swap(val.s1, val.s2);
	std::cout << "Post-swap: s1 = " << val.s1 << ", s2 = " << val.s2 << std::endl;
	std::cout << "Minimum = " << ::min(val.s1, val.s2) << std::endl;
	std::cout << "Maximum = " << ::max(val.s1, val.s2) << std::endl;
	std::cout << std::endl;

	// Compilation will fail
	//::swap(val.ic1, val.ic2); // const int and const int
	//::swap(val.i1, val.ic1); // int annd const int

	return (0);
}
