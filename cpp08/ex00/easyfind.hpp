#pragma once

#include <stdexcept>
#include <concepts>

// Concepts for validating type traits
template <typename T>
concept is_container = requires(T type)
{
	{ type.empty() } -> std::same_as<decltype(type.empty())>;
	{ type.begin() } -> std::same_as<decltype(type.end())>;
	{ type.cbegin() } -> std::same_as<decltype(type.cend())>;
};

template <typename T>
concept is_map = is_container<T> && requires
{
	typename T::key_type;
	typename T::mapped_type;
	{ std::declval<T>().find(std::declval<typename T::key_type>())} -> std::same_as<typename T::iterator>;
};

template <typename T, typename U>
concept contains_similar = requires { typename T::value_type; } &&
(
	(requires { typename T::mapped_type; } && std::same_as<typename T::mapped_type, U>)
	|| std::same_as<typename T::value_type, U>
);

// Mandatory
template <typename T>
requires is_container<T> && (!is_map<T>) && contains_similar<T, int>
auto	easyfind( const T& container, const int& val ) -> decltype(auto)
{
	for (const auto& c : container)
	{
		if (c == val)
			return (c);
	}
	throw (std::runtime_error("value could not be found"));
}

// Overload with templated second parameter
template <typename T, typename U>
requires is_container<T> && (!is_map<T>) && contains_similar<T, U>
auto	easyfind( const T& container, const U& val ) -> decltype(auto)
{
	for (const auto& c : container)
	{
		if (c == val)
			return (c);
	}
	throw (std::runtime_error("value could not be found"));
}

// Specific to key/value paired containers
template <typename T>
requires is_container<T> && is_map<T> && contains_similar<T, int>
auto	easyfind( const T& container, const int& val ) -> decltype(auto)
{
	for (const auto& c : container)
	{
		if (c.second == val)
			return (c.second);
	}
	throw (std::runtime_error("value could not be found"));
}

template <typename T, typename U>
requires is_container<T> && is_map<T> && contains_similar<T, U>
auto	easyfind( const T& container, const U& val ) -> decltype(auto)
{
	for (const auto& c : container)
	{
		if (c.second == val)
			return (c.second);
	}
	throw (std::runtime_error("value could not be found"));
}
