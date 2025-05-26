#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main( void )
{
	AForm*		form = nullptr;
	Intern		bot;

	try
	{
		Bureaucrat	person("Marvin", 70);

		form = bot.makeForm("shrubbery creation", "home");
		if (form)
		{
			std::cout << *form << std::endl;
			person.signForm( *form );
			person.executeForm( *form );
			delete (form);
			form = nullptr;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error caught: " << e.what() << std::endl;
		if (form)
		{
			delete (form);
			form = nullptr;
		}
	}
	return (0);
}
