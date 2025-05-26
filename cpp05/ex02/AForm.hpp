#pragma once

#include <iostream>

#ifndef GRADE_MIN
# define GRADE_MIN 150
#endif
#ifndef GRADE_MAX
# define GRADE_MAX 1
#endif

class Bureaucrat;

class AForm
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
		class ExecutionNotAllowedException : public std::exception
		{
			private:
				std::string	_whatMessage;
			public:
				ExecutionNotAllowedException( void );
				const char*	what( void ) const noexcept override;
		};

	public:
		AForm() = delete;
		AForm( const std::string name, const int signGrade, const int executeGrade );
		AForm( const AForm& other );
		AForm&	operator=( const AForm& other ) = delete; // Cannot modify immutable variables
		virtual ~AForm() = 0; // Pure virtual to block instantiation

		std::string		getName()			const noexcept;
		bool			getSigned()			const noexcept;
		int				getSignageGrade()	const noexcept;
		int				getExecutionGrade()	const noexcept;

		virtual void	beSigned( Bureaucrat& person );
		virtual void	execute( Bureaucrat const & executor ) const;

	protected:
		virtual void	action( const std::string target ) const = 0;
};

std::ostream& operator<<( std::ostream& os, const AForm& obj);
