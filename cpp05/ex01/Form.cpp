#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor and destructor

Form::Form( const std::string name, const int signGrade, const int executeGrade ) :
	_name(name),
	_signed(false),
	_signageGrade(
		(signGrade < GRADE_MAX ? throw (Form::GradeTooHighException()) :
		(signGrade > GRADE_MIN ? throw (Form::GradeTooLowException()) : signGrade))
	),
	_executionGrade(
		(executeGrade < GRADE_MAX ? throw (Form::GradeTooHighException()) :
		(executeGrade > GRADE_MIN ? throw (Form::GradeTooLowException()) : executeGrade))
	) {}

Form::Form( const Form& other ) :
	_name(other._name),
	_signed(other._signed),
	_signageGrade(other._signageGrade),
	_executionGrade(other._executionGrade) {}

Form::~Form() {}

// Getters

std::string	Form::getName() const noexcept { return (_name); }

bool	Form::getSigned() const noexcept { return (_signed); }

int	Form::getSignageGrade() const noexcept { return (_signageGrade); }

int	Form::getExecutionGrade() const noexcept { return (_executionGrade); }

// Insertion operator

std::ostream& operator<<( std::ostream& os, const Form& obj)
{
	os << "Form " << obj.getName() << (obj.getSigned() == true ? " is signed. " : " is not signed. ")
	<< "Grade to sign: " << obj.getSignageGrade() << ", Grade to execute: " << obj.getExecutionGrade() << ".";

	return (os);
}

// Exceptions

Form::GradeTooHighException::GradeTooHighException( void ) { _whatMessage = "grade was too high"; }

const char*	Form::GradeTooHighException::what( void ) const noexcept { return (_whatMessage.c_str()); }

Form::GradeTooLowException::GradeTooLowException( void ) { _whatMessage = "grade was too low"; }

const char*	Form::GradeTooLowException::what( void ) const noexcept { return (_whatMessage.c_str()); }

Form::AlreadySignedException::AlreadySignedException( void ) { _whatMessage = "form was already signed"; }

const char*	Form::AlreadySignedException::what( void ) const noexcept { return (_whatMessage.c_str()); }

// Additional member function

void	Form::beSigned( Bureaucrat& person )
{
	if (_signed == true)
		throw (Form::AlreadySignedException());
	if (person.getGrade() > _signageGrade)
		throw (Form::GradeTooLowException());
	_signed = true;
}
