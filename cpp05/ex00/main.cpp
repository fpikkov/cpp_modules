#include "Bureaucrat.hpp"

static void	dummy_george( void )
{
	try
	{
		Bureaucrat george;

		std::cout << george << std::endl;

		std::cout << "Decrementing " << george.getName() << "'s grade" << std::endl;
		george.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	dummy_john( void )
{
	try
	{
		std::string name = "John";
		int			grade = -1000;

		Bureaucrat john(name, grade);

		std::cout << john << std::endl;

		std::cout << "Incrementing " << john.getName() << "'s grade" << std::endl;
		john.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	dummy_mike( void )
{
	try
	{
		std::string name = "Mike";
		int			grade = 1;

		Bureaucrat mike(name, grade);

		std::cout << mike << std::endl;

		std::cout << "Incrementing " << name << "'s grade" << std::endl;
		mike.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	dummy_duo( void )
{
	try
	{
		Bureaucrat george;
		Bureaucrat mike("Mike", 100);

		std::cout << george << std::endl;
		std::cout << mike << std::endl;

		std::cout << "Assigning " << mike.getName() << " to " << george.getName() << std::endl;
		george = mike;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main( void )
{
	std::cout << "\033[32;1m" << "Mike => incrementing" << "\033[0m" << std::endl;
	dummy_mike();

	std::cout << "\033[32;1m" << "George => decrementing" << "\033[0m" << std::endl;
	dummy_george();

	std::cout << "\033[32;1m" << "John => instantiating out of range" << "\033[0m" << std::endl;
	dummy_john();

	std::cout << "\033[32;1m" << "George & John => assignment" << "\033[0m" << std::endl;
	dummy_duo();

	return (0);
}
