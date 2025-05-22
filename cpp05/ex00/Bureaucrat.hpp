#pragma once

#include <iostream>

#define GRADE_MIN 150
#define GRADE_MAX 1

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

		class GradeTooHighException : public std::exception
		{
			private:
				std::string	_whatMessage;
			public:
				GradeTooHighException( void );
				const char*	what( void ) const noexcept override;
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string	_whatMessage;
			public:
				GradeTooLowException( void );
				const char*	what( void ) const noexcept override;
		};
		class ConstantException : public std::exception
		{
			private:
				std::string	_whatMessage;
			public:
				ConstantException( void );
				const char*	what( void ) const noexcept override;
		};

	public:
		Bureaucrat( void );
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat&	operator=( const Bureaucrat& other );
		~Bureaucrat();

		std::string	getName( void ) const;
		int			getGrade( void ) const;

		void		incrementGrade( void );
		void		decrementGrade( void );
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& obj);
