#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base*	Base::generate()
{
	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<>	distrib(0, 2);

	int random = distrib(gen);

	if (random == 0)
		return (dynamic_cast<Base*>(new A()));
	else if (random == 1)
		return (dynamic_cast<Base*>(new B()));
	return (dynamic_cast<Base*>(new C()));
}

void	Base::identify( Base* p )
{
	std::cout << "Identified pointer as: " << (
		dynamic_cast<A*>(p) ? "A" :
		dynamic_cast<B*>(p) ? "B" :
		dynamic_cast<C*>(p) ? "C" :"Unknown") << std::endl;
}

void	Base::identify( Base& p )
{
	try
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "Identified reference as: A" << std::endl;
	}
	catch(const std::bad_cast&)
	{
		try
		{
			static_cast<void>(dynamic_cast<B&>(p));
			std::cout << "Identified reference as: B" << std::endl;
		}
		catch(const std::bad_cast&)
		{
			try
			{
				static_cast<void>(dynamic_cast<C&>(p));
				std::cout << "Identified reference as: C" << std::endl;
			}
			catch(const std::bad_cast&)
			{
				std::cout << "Unknwon reference to class" << std::endl;
			}
		}
	}
}
