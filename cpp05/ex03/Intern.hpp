#pragma once

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#ifdef NAMES_AMOUNT
# undef NAMES_AMOUNT
#endif
#define NAMES_AMOUNT 30

class Intern
{
	private:
		enum EForms
		{
			PRESIDENT = 0,
			SHRUBBERY = 10,
			ROBOTOMY = 20,
			GENERIC = 30,
		};
		class FormInvalidException : public std::exception
		{
			private:
				std::string	_whatMessage;
			public:
				FormInvalidException( void );
				const char*	what( void ) const noexcept override;
		};

		EForms	convertToEnum( const std::string name ) const;

	public:
		Intern();
		Intern( const Intern& other ) = delete;
		Intern&	operator=(const Intern& other ) = delete;
		~Intern();

		AForm*	makeForm( const std::string formName, const std::string target );
};
