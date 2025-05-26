#pragma once

#include "AForm.hpp"

#ifdef PRESIDENTIAL_SIGN_GRADE
# undef PRESIDENTIAL_SIGN_GRADE
#endif
#define PRESIDENTIAL_SIGN_GRADE 25

#ifdef PRESIDENTIAL_EXEC_GRADE
# undef PRESIDENTIAL_EXEC_GRADE
#endif
#define PRESIDENTIAL_EXEC_GRADE 5

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm() = delete;
		PresidentialPardonForm( const std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		PresidentialPardonForm&	operator=( const PresidentialPardonForm& other ) = delete;
		~PresidentialPardonForm() override;

		void	beSigned( Bureaucrat& person ) override;
		void	execute( Bureaucrat const & executor ) const override;

	protected:
		void	action() const override;

};
