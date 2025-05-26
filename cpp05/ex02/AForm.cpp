#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor and destructor

AForm::AForm( const std::string name, const int signGrade, const int executeGrade ) :
	_name(name),
	_signed(false),
	_signageGrade(
		(signGrade < GRADE_MAX ? throw (AForm::GradeTooHighException()) :
		(signGrade > GRADE_MIN ? throw (AForm::GradeTooLowException()) : signGrade))
	),
	_executionGrade(
		(executeGrade < GRADE_MAX ? throw (AForm::GradeTooHighException()) :
		(executeGrade > GRADE_MIN ? throw (AForm::GradeTooLowException()) : executeGrade))
	) {}

AForm::AForm( const AForm& other ) :
	_name(other._name),
	_signed(other._signed),
	_signageGrade(other._signageGrade),
	_executionGrade(other._executionGrade) {}

AForm::~AForm() {}

// Getters

std::string	AForm::getName() const noexcept { return (_name); }

bool	AForm::getSigned() const noexcept { return (_signed); }

int	AForm::getSignageGrade() const noexcept { return (_signageGrade); }

int	AForm::getExecutionGrade() const noexcept { return (_executionGrade); }

// Insertion operator

std::ostream& operator<<( std::ostream& os, const AForm& obj)
{
	os << "AForm " << obj.getName() << (obj.getSigned() == true ? " is signed. " : " is not signed. ")
	<< "Grade to sign: " << obj.getSignageGrade() << ", Grade to execute: " << obj.getExecutionGrade() << ".";

	return (os);
}

// Exceptions

AForm::GradeTooHighException::GradeTooHighException( void ) { _whatMessage = "grade was too high"; }

const char*	AForm::GradeTooHighException::what( void ) const noexcept { return (_whatMessage.c_str()); }

AForm::GradeTooLowException::GradeTooLowException( void ) { _whatMessage = "grade was too low"; }

const char*	AForm::GradeTooLowException::what( void ) const noexcept { return (_whatMessage.c_str()); }

AForm::AlreadySignedException::AlreadySignedException( void ) { _whatMessage = "form was already signed"; }

const char*	AForm::AlreadySignedException::what( void ) const noexcept { return (_whatMessage.c_str()); }

AForm::ExecutionNotAllowedException::ExecutionNotAllowedException( void ) { _whatMessage = "form not signed, can not execute"; }

const char*	AForm::ExecutionNotAllowedException::what( void ) const noexcept { return (_whatMessage.c_str()); }

// Additional member function

void	AForm::beSigned( Bureaucrat& person )
{
	if (_signed == true)
		throw (AForm::AlreadySignedException());
	if (person.getGrade() > _signageGrade)
		throw (AForm::GradeTooLowException());
	_signed = true;
}

void	AForm::execute( Bureaucrat const & executor ) const
{
	if (!_signed)
		throw (AForm::ExecutionNotAllowedException());
	if (executor.getGrade() > _executionGrade)
		throw (AForm::GradeTooLowException());
}
