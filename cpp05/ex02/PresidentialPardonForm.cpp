#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructors

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) :
	AForm( "Presidential Pardon", PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXEC_GRADE, target ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm( other ) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

// Additional member functions

void	PresidentialPardonForm::beSigned( Bureaucrat& person ) { AForm::beSigned( person ); }

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	AForm::execute( executor );
	this->action();
}

void	PresidentialPardonForm::action() const
{
	std::cout << "\033[32:1m" << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << "\033[0m" << std::endl;
}


