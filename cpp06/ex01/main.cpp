#include "Serializer.hpp"
#include "Data.hpp"

static void	printContents( Data d )
{
	std::cout << "Char: " << d._valChar << std::endl;
	std::cout << "Int: " << d._valInt << std::endl;
	std::cout << "String: " << d._valString << std::endl;
}

int	main()
{
	uintptr_t	ptr;
	Data		data;
	Data*		dataPtr = nullptr;

	data._valChar = 'c';
	data._valInt = 420;
	data._valString = "Hello, World";

	std::cout << "=== Original struct ===" << std::endl;
	printContents(data);
	std::cout << std::endl;

	ptr = Serializer::serialize(&data);
	dataPtr = Serializer::deserialize(ptr);

	std::cout << "=== Serialized struct ===" << std::endl;
	printContents(*dataPtr);
	std::cout << std::endl;

	if (dataPtr == &data)
		std::cout << "Serialization successful" << std::endl;
	else
		std::cout << "Serialization unsuccessful" << std::endl;

	return (0);
}
