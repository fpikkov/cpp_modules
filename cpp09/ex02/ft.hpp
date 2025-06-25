#pragma once

#include <iterator>
#include <concepts>
#include <string>
#include <sstream>
#include <stdexcept>

namespace ft
{
	template <typename T>
	concept container = requires( T type )
	{
		typename T::value_type;
		typename T::iterator;

		{ type.begin() } -> std::input_iterator;
		{ type.end() } -> std::input_iterator;
		{ type.empty() } -> std::same_as<decltype(type.empty())>;
	};

	template<typename T>
	constexpr auto rightmost( const T& val ) -> const T& { return (val); }


	template<typename T>
	constexpr auto rightmost( const std::pair<T, T>& val ) -> const auto& { return (rightmost(val.second)); }

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

	template<typename T>
	auto make_ordered_pair( const T& a, const T& b ) -> std::pair<T, T>
	{
		if constexpr (std::is_integral_v<T>)
			return ( (a < b) ? std::make_pair(a, b) : std::make_pair(b, a) );
		return ( (rightmost(a) < rightmost(b)) ? std::make_pair(a, b) : std::make_pair(b, a) );
	}

	auto args_to_string( int argc, char** argv ) -> std::string;
};
