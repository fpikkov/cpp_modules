#include "Intern.hpp"

static const std::string	g_names[NAMES_AMOUNT] =
{
	"Presidential Pardon",
	"Presidential Pardon Form",
	"PresidentialPardon",
	"PresidentialPardonForm",
	"presidentialpardon",
	"presidentialpardonform",
	"presidential_pardon",
	"presidential_pardon_form",
	"presidential pardon",
	"presidential pardon form", // 0 to 9
	"Shrubbery Creation",
	"Shrubbery Creation Form",
	"ShrubberyCreation",
	"ShrubberyCreationForm",
	"shrubberycreation",
	"shrubberycreationform",
	"shrubbery_creation",
	"shrubbery_creation_form",
	"shrubbery creation",
	"shrubbery creation form", // 10 to 19
	"Robotomy Request",
	"Robotomy Request Form",
	"RobotomyRequest",
	"RobotomyRequestForm",
	"robotomyrequest",
	"robotomyrequestform",
	"robotomy_request",
	"robotomy_request_form",
	"robotomy request",
	"robotomy request form", // 20 to 29
};

// Constructors and destructors

Intern::Intern() {}

Intern::~Intern() {}

// Member functions

Intern::EForms	Intern::convertToEnum( const std::string name ) const
{
	Intern::EForms	type;
	int				i;

	for (i = 0; i < NAMES_AMOUNT; ++i)
	{
		if ((!g_names[i].empty()) && (g_names[i].compare(name) == 0))
			break ;
	}
	if (i == GENERIC)
		throw (Intern::FormInvalidException());
	type = Intern::EForms((i / 10) * 10);
	return (type);
}

AForm*	Intern::makeForm( const std::string formName, const std::string target )
{
	AForm*	form = nullptr;
	EForms	type;

	try
	{
		type = convertToEnum(formName);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Intern error: " << e.what() << std::endl;
		return (nullptr);
	}
	switch (type)
	{
		case PRESIDENT:
			form = new PresidentialPardonForm(target);
			break ;
		case SHRUBBERY:
			form = new ShrubberyCreationForm(target);
			break ;
		case ROBOTOMY:
			form = new RobotomyRequestForm(target);
			break ;
		default:
			throw (Intern::FormInvalidException());
			break ;
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);
}

// Exceptions

Intern::FormInvalidException::FormInvalidException( void ) { _whatMessage = "such a form is not available"; }

const char*	Intern::FormInvalidException::what( void ) const noexcept { return (_whatMessage.c_str()); }
