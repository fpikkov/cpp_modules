#pragma once

#include <iostream>

#ifndef GRADE_MIN
# define GRADE_MIN 150
#endif
#ifndef GRADE_MAX
# define GRADE_MAX 1
#endif

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signageGrade;
		const int			_executionGrade;

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
		class AlreadySignedException : public std::exception
		{
			private:
				std::string	_whatMessage;
			public:
				AlreadySignedException( void );
				const char*	what( void ) const noexcept override;
		};

	public:
		Form() = delete;
		Form( const std::string name, const int signGrade, const int executeGrade );
		Form( const Form& other );
		Form&	operator=( const Form& other ) = delete;
		~Form();

		std::string	getName()			const noexcept;
		bool		getSigned()			const noexcept;
		int			getSignageGrade()	const noexcept;
		int			getExecutionGrade()	const noexcept;

		void		beSigned( Bureaucrat& person );
};

std::ostream& operator<<( std::ostream& os, const Form& obj);
