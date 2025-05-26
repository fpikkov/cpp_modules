#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void )
{
	try
	{
		Bureaucrat				person("Landor", 70);
		ShrubberyCreationForm	shrub("darkwood");

		std::cout << shrub << std::endl;

		person.signForm( shrub );
		shrub.execute( person );
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
