#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

static const std::string	g_noises[NOISES_MAX] =
{
	"**Brrrrrrrrrrr**",
	"**Brbrbrbrbrrr**",
	"**Rrrbrrrbrrrr**",
	"**Kchnk**",
	"**Brrrt**",
	"**Rrrt-rrt**"
};

// Constructors and destructors

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) :
	AForm( "Robotomy", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE, target ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm( other ) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Additional member functions

void	RobotomyRequestForm::beSigned( Bureaucrat& person ) { AForm::beSigned( person ); }

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	AForm::execute( executor );
	this->action();
}

void	RobotomyRequestForm::action() const
{
	// Randomizer with equal distribution
	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<>	success(0, 1);
	std::uniform_int_distribution<>	distrib(0, NOISES_MAX - 1);

	int	iterations = distrib(gen) + 1;
	std::cout << std::endl;
	for (int i = 0; i < iterations; ++i)
	{
		std::cout << g_noises[distrib(gen)] << std::endl;
	}
	std::cout << std::endl;

	// Was the robotomy sucessful
	if (success(gen) == true)
	{
		std::cout << "\033[32:1m" << this->getTarget() << " has been robotomized." << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[31:1m" << this->getTarget() << " robotomy has failed." << "\033[0m" << std::endl;
	}
}
