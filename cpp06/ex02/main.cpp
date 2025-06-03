#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define AMOUNT 6

int	main()
{
	Base	based;

	Base*	basePtr = nullptr;

	std::cout << "\033[32;1m === HEAP ALLOCATION === \033[0m" << std::endl;
	for (size_t i = 0; i < AMOUNT; ++i)
	{
		basePtr = based.generate();

		based.identify(basePtr);
		based.identify(*basePtr);

		if (basePtr)
		{
			delete basePtr;
			basePtr = nullptr;
		}
	}

	std::cout << "\033[32;1m === STACK ALLOCATION === \033[0m" << std::endl;
	A	a;
	basePtr = &a;
	based.identify(basePtr);
	based.identify(*basePtr);
	B	b;
	basePtr = &b;
	based.identify(basePtr);
	based.identify(*basePtr);
	C	c;
	basePtr = &c;
	based.identify(basePtr);
	based.identify(*basePtr);

	basePtr = nullptr;
	based.identify(basePtr);
	based.identify(*basePtr);

	return (0);
}
