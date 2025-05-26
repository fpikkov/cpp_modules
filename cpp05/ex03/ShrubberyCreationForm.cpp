#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

static const std::string	g_trees[TREES_MAX] =
{
R"(
        &&& &&  & &&
      && &\/&\|& |/ @, &&
      &\//&/&||/& /_/_&/_&
    & &\/&||/&\/ % & / /&_ &
   &_\_&&_\ |& |&&/&__%_/_& &&
 &&   && & &| &| /& & % & /&&
 &_---&\&\|&&-&&--%---~
     &&     \|||
             |||
             |||
             |||
       , -=-~  .-^- _
)",
R"(
          &&& &&  & &&
      && &\/&\|& ()|/ @, &&
      &\/(/&/&||/& /_/)_&/_&
    &() &\/&|()|/&\/ '%" & ()
   &_\_&&_\ |& |&&/&__%_/_& &&
 &&   && & &| &| /& & % ()& /&&
 ()&_---()&\&\|&&-&&--%---()~
     &&     &&&
             |||
             |||
             |||
             |||
)",
R"(
      &&&&&&&&
    &&& &&* && &
   &&& *-_&&& *&&
  *&&&&_*|&&_*&&
      \ ||| &&
       \||| /&
        |||/
        |||
        |||=-_
)"
};

// Constructors and destructors

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) :
	AForm( "Shrubbery Creation", SHRUB_SIGN_GRADE, SHRUB_EXEC_GRADE, target ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm( other ) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Additional member functions

void	ShrubberyCreationForm::beSigned( Bureaucrat& person ) { AForm::beSigned( person ); }

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	AForm::execute( executor );
	this->action();
}

void	ShrubberyCreationForm::action() const
{
	// Random number generator
	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<>	distrib(0, TREES_MAX - 1);

	// File handling
	std::string		destination;
	std::ofstream	bush;

	destination = this->getTarget() + "_shrubbery";
	bush.open(destination.c_str(), std::ios::app);

	if (!bush)
		throw (ShrubberyCreationForm::NoAuthorityException());

	// Plant random tree from a list of available ones
	for (int i = 0; i < SHRUBERY_MAX; ++i)
	{
		bush << g_trees[distrib(gen)];
	}

	if (bush)
		bush.close();

	std::cout << "\033[32:1m" << "Shrubbery created in " << destination << "." << "\033[0m" << std::endl;
}

// Exception

ShrubberyCreationForm::NoAuthorityException::NoAuthorityException( void ) { _whatMessage = "plot of land was unavailable"; }

const char*	ShrubberyCreationForm::NoAuthorityException::what( void ) const noexcept { return (_whatMessage.c_str()); }
