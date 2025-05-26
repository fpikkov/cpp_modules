#pragma once

#include "AForm.hpp"
#include <fstream>
#include <random>

#ifdef SHRUB_SIGN_GRADE
# undef SHRUB_SIGN_GRADE
#endif
#define SHRUB_SIGN_GRADE 145

#ifdef SHRUB_EXEC_GRADE
# undef SHRUB_EXEC_GRADE
#endif
#define SHRUB_EXEC_GRADE 137

#ifdef SHRUBERY_MAX
# undef SHRUBERY_MAX
#endif
#define SHRUBERY_MAX 6

#ifdef TREES_MAX
# undef TREES_MAX
#endif
#define TREES_MAX 4

class ShrubberyCreationForm : public AForm
{
	private:
		class NoAuthorityException : public std::exception
		{
			private:
				std::string	_whatMessage;
			public:
				NoAuthorityException( void );
				const char*	what( void ) const noexcept override;
		};

	public:
		ShrubberyCreationForm() = delete;
		ShrubberyCreationForm( const std::string name );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& other ) = delete;
		~ShrubberyCreationForm() override;

		void	beSigned( Bureaucrat& person ) override;
		void	execute( Bureaucrat const & executor ) const override;

	protected:
		void	action( const std::string target ) const override;
};
