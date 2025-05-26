#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main( void )
{
	// Test shrubbery creation
	try
	{
		Bureaucrat				person("Arthur", 70);
		ShrubberyCreationForm	shrub("yard");

		std::cout << shrub << std::endl;

		person.signForm( shrub );
		shrub.execute( person ); // <<== replace with Bureaucrat execution
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Test robotomy
	try
	{
		Bureaucrat	person("Marvin", 45);
		int			iterations = 5;

		for (int i = 0; i < iterations; ++i)
		{
			RobotomyRequestForm	robotomy("parking_lot");

			person.signForm( robotomy );
			robotomy.execute( person );
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
