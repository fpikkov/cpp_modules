#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	// Test: initializing with wrong values
	try
	{
		Form	mandate("Mandate of Authority", -1, 500);
		std::cout << Form(mandate) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Form: " << e.what() << std::endl;
	}

	// Test: signing with invalid bureaucrat grade
	try
	{
		Bureaucrat	person("Landor", 70);

		Form	lex("Lex Imperialis", 100, 80);
		Form	writ("Writ of Sanction", 60, 40);

		std::cout << lex << std::endl;
		std::cout << writ << std::endl;

		person.signForm( lex );
		person.signForm( lex );
		person.signForm( writ );
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
