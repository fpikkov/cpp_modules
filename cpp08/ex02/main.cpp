#include "MutantStack.hpp"

#include <iostream>
#include <list>

static void mutant_test();
static void list_test();
static void custom_test();

#define TEST_SIZE 10

int main()
{
	mutant_test();
	list_test();
	custom_test();

	return (0);
}

static void mutant_test()
{
	std::cout << "\033[32;1m=== Mutant Stack ===\033[0m" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
}

// List does NOT have pop() and push() available
static void list_test()
{
	std::cout << "\033[32;1m=== List ===\033[0m" << std::endl;

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::list<int> l(list);
}

// Testing whether assignment operator works correctly and that both const and non-const iterators work
static void custom_test()
{
	std::cout << "\033[32;1m=== Custom Test ===\033[0m" << std::endl;

	MutantStack<int> _ms1;
	MutantStack<int> _ms2;

	for (size_t idx = 0; idx < TEST_SIZE; ++idx)
		_ms1.push(static_cast<int>(idx));

	std::cout << "Numbers in 1: ";
	for (auto& it : _ms1)
		std::cout << it << " ";
	std::cout << std::endl;

	std::cout << "Calling assignment operator" << std::endl;
	_ms2 = _ms1;

	MutantStack<int>::const_iterator cit = _ms2.cbegin();
	MutantStack<int>::const_iterator cite = _ms2.cend();
	std::cout << "Numbers in 2: ";
	while (cit != cite)
	{
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;

	MutantStack<int> _ms3 = std::move(_ms2);
}
