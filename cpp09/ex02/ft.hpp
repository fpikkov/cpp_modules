#pragma once

#include <iterator>
#include <concepts>
#include <string>
#include <sstream>
#include <stdexcept>

namespace ft
{
	template <typename T>
	concept container = requires(T type)
	{
		typename T::value_type;
		typename T::iterator;
	
		{ type.begin() } -> std::input_iterator;
		{ type.end() } -> std::input_iterator;
		{ type.empty() } -> std::same_as<decltype(type.empty())>;
	};

	template <std::integral T, container C>
	auto string_to_container( const std::string& str, C& values ) -> void
	{
		std::istringstream	sstream(str);
		T					val;

		while (sstream >> val)
			values.insert(values.end(), val);
		if (!sstream.eof())
			throw (std::runtime_error("Error: failed to parse integral values"));
	}

	auto args_to_string( int argc, char** argv ) -> std::string;
};
