#include "easyfind.hpp"

#include <iostream>
#include <iomanip>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

#include <set>
#include <map>

#define MAX 10

static void	test_vector();
static void	test_array();
static void	test_deque();
static void	test_forward_list();
static void	test_list();
static void	test_set();
static void	test_multiset();
static void	test_map();
static void	test_multimap();
static void	test_vector_overload();
static void	test_multimap_overload();

int	main()
{
	std::cout << std::fixed << std::setprecision(2);

	// Sequence containers
	test_array();
	test_vector();
	test_deque();
	test_forward_list();
	test_list();

	// Associative containers
	test_set();
	test_multiset();
	test_map();
	test_multimap();

	// Overloaded to accept any variable
	test_vector_overload();
	test_multimap_overload();

	return (0);
}

static void	test_array()
{
	std::array<int, MAX> _arr;
	std::cout << "\033[32;1m === Testing array === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_arr[idx] = static_cast<int>(idx);

		auto res = easyfind(_arr, MAX - 1);
		std::cout << res << " was found within the array." << std::endl;

		res = easyfind(_arr, MAX);
		std::cout << res << " was found within the array." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "Array: " << e.what() << '\n'; std::cout << '\n';}
}

static void	test_vector()
{
	std::vector<int> _vec;
	std::cout << "\033[32;1m === Testing vector === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_vec.push_back(static_cast<int>(idx));

		auto res = easyfind(_vec, MAX - 1);
		std::cout << res << " was found within the vector." << std::endl;

		res = easyfind(_vec, MAX);
		std::cout << res << " was found within the vector." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "Vector: " << e.what() << '\n'; std::cout << '\n';}
}

static void	test_deque()
{
	std::deque<int> _deq;
	std::cout << "\033[32;1m === Testing double-ended queue === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_deq.push_back(static_cast<int>(idx));

		auto res = easyfind(_deq, MAX - 1);
		std::cout << res << " was found within the double-ended queue." << std::endl;

		res = easyfind(_deq, MAX);
		std::cout << res << " was found within the double-ended queue." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "Deque: " << e.what() << '\n'; std::cout << '\n';}
}

static void	test_forward_list()
{
	std::forward_list<int> _flist;
	std::cout << "\033[32;1m === Testing forward list === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_flist.push_front(static_cast<int>(idx));

		auto res = easyfind(_flist, MAX - 1);
		std::cout << res << " was found within the forward list." << std::endl;

		res = easyfind(_flist, MAX);
		std::cout << res << " was found within the forward list." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "Forward list: " << e.what() << '\n'; std::cout << '\n';}
}

static void	test_list()
{
	std::list<int> _list;
	std::cout << "\033[32;1m === Testing list === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_list.push_back(static_cast<int>(idx));

		auto res = easyfind(_list, MAX - 1);
		std::cout << res << " was found within the list." << std::endl;

		res = easyfind(_list, MAX);
		std::cout << res << " was found within the list." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "List: " << e.what() << '\n'; std::cout << '\n';}
}

static void	test_set()
{
	std::set<int> _set;
	std::cout << "\033[32;1m === Testing set === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_set.insert(static_cast<int>(idx));

		auto res = easyfind(_set, MAX - 1);
		std::cout << res << " was found within the set." << std::endl;

		res = easyfind(_set, MAX);
		std::cout << res << " was found within the set." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "Set: " << e.what() << '\n'; std::cout << '\n';}
}

static void	test_multiset()
{
	std::multiset<int> _mset;
	std::cout << "\033[32;1m === Testing multiset === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_mset.insert(static_cast<int>(idx));

		auto res = easyfind(_mset, MAX - 1);
		std::cout << res << " was found within the multiset." << std::endl;

		res = easyfind(_mset, MAX);
		std::cout << res << " was found within the multiset." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "Multiset: " << e.what() << '\n'; std::cout << '\n';}
}

static void	test_map()
{
	std::map<size_t, int> _map;
	std::cout << "\033[32;1m === Testing map === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_map.insert({idx, static_cast<int>(idx)});

		auto res = easyfind(_map, MAX - 1);
		std::cout << res << " was found within the map." << std::endl;

		res = easyfind(_map, MAX);
		std::cout << res << " was found within the map." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "Map: " << e.what() << '\n'; std::cout << '\n';}
}

static void	test_multimap()
{
	std::multimap<size_t, int> _mmap;
	std::cout << "\033[32;1m === Testing multimap === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_mmap.insert({idx, static_cast<int>(idx)});

		auto res = easyfind(_mmap, MAX - 1);
		std::cout << res << " was found within the multimap." << std::endl;

		res = easyfind(_mmap, MAX);
		std::cout << res << " was found within the multimap." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "Multimap: " << e.what() << '\n'; std::cout << '\n';}
}

static void	test_vector_overload()
{
	std::vector<float> _vec;
	std::cout << "\033[36;1m === Testing vector with floats === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_vec.push_back(static_cast<float>(idx));

		auto res = easyfind(_vec, static_cast<float>(MAX - 1));
		std::cout << res << " was found within the vector." << std::endl;

		res = easyfind(_vec, static_cast<float>(MAX));
		std::cout << res << " was found within the vector." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "Vector: " << e.what() << '\n'; std::cout << '\n';}
}

static void	test_multimap_overload()
{
	std::multimap<size_t, double> _mmap;
	std::cout << "\033[36;1m === Testing multimap with doubles === \033[0m" << std::endl;
	try
	{
		for (size_t idx = 0; idx < MAX; ++idx)
			_mmap.insert({idx, static_cast<double>(idx)});

		auto res = easyfind(_mmap, static_cast<double>(MAX - 1));
		std::cout << res << " was found within the multimap." << std::endl;

		res = easyfind(_mmap, static_cast<double>(MAX));
		std::cout << res << " was found within the multimap." << std::endl;
	}
	catch(const std::exception& e) {std::cerr << "Multimap: " << e.what() << '\n'; std::cout << '\n';}
}
