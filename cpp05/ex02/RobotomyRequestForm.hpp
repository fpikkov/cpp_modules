#pragma once

#include "AForm.hpp"
#include <random>

#ifdef ROBOTOMY_SIGN_GRADE
# undef ROBOTOMY_SIGN_GRADE
#endif
#define ROBOTOMY_SIGN_GRADE 72

#ifdef ROBOTOMY_EXEC_GRADE
# undef ROBOTOMY_EXEC_GRADE
#endif
#define ROBOTOMY_EXEC_GRADE 45

#ifdef NOISES_MAX
# undef NOISES_MAX
#endif
#define NOISES_MAX 6

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm() = delete;
		RobotomyRequestForm( const std::string name );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& other ) = delete;
		~RobotomyRequestForm() override;

		void	beSigned( Bureaucrat& person ) override;
		void	execute( Bureaucrat const & executor ) const override;

	protected:
		void	action( const std::string target ) const override;
};
