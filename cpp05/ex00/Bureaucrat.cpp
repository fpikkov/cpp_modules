#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("George"), _grade(GRADE_MIN)
{

}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name)
{
	if (grade < GRADE_MAX)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > GRADE_MIN)
		throw (Bureaucrat::GradeTooLowException());
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other._name), _grade(other._grade)
{

}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
	{
		throw (Bureaucrat::ConstantException());
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string	Bureaucrat::getName( void ) const
{
	return (_name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade( void )
{
	if (_grade - 1 < GRADE_MAX)
		throw (Bureaucrat::GradeTooHighException());
	else
		--_grade;
}

void	Bureaucrat::decrementGrade( void )
{
	if (_grade + 1 > GRADE_MIN)
		throw (Bureaucrat::GradeTooLowException());
	else
		++_grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException( void )
{
	_whatMessage = "Bureaucrat: Grade was too high.";
}

const char*	Bureaucrat::GradeTooHighException::what( void ) const noexcept
{
	return (_whatMessage.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException( void )
{
	_whatMessage = "Bureaucrat: Grade was too low.";
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const noexcept
{
	return (_whatMessage.c_str());
}

Bureaucrat::ConstantException::ConstantException( void )
{
	_whatMessage = "Bureaucrat: Unable to modify an immutable value";
}

const char*	Bureaucrat::ConstantException::what( void ) const noexcept
{
	return (_whatMessage.c_str());
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";

	return (os);
}
