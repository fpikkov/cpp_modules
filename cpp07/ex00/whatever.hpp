#pragma once

#include <type_traits>

// Type predicate / concept emulator

template <typename T, typename U, typename = void>
struct is_comparable : std::false_type {};

template <typename T, typename U>
struct is_comparable <T, U, std::void_t<
	decltype(std::declval<T>() == std::declval<U>()),
	decltype(std::declval<T>() != std::declval<U>()),
	decltype(std::declval<T>() <= std::declval<U>()),
	decltype(std::declval<T>() >= std::declval<U>()),
	decltype(std::declval<T>() < std::declval<U>()),
	decltype(std::declval<T>() > std::declval<U>())
>> : std::true_type {};

template <typename T, typename U>
inline constexpr bool is_comparable_v = is_comparable<T, U>::value;


// Swap template

template <typename T>
void	swap(T& a, T& b)
{
	static_assert(!std::is_const_v<T>, "swap requires mutable values");
	static_assert(std::is_same_v<decltype(a), decltype(b)>, "values are of a different type");
	static_assert(is_comparable_v<decltype(a), decltype(b)>, "values can not be compared");

	if (&a == &b)
		return ;

	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void	swap(T* a, T* b)
{
	static_assert(std::is_pointer_v<T*>, "swap requires pointer types");
	static_assert(!std::is_const_v<T>, "swap requires mutable values");
	static_assert(std::is_same_v<decltype(*a), decltype(*b)>, "values are of a different type");
	static_assert(is_comparable_v<decltype(*a), decltype(*b)>, "values can not be compared");

	if (a == b)
		return ;

	T temp = *a;
	*a = *b;
	*b = temp;
}

// Min template

template <typename T>
T	min(T& a, T& b)
{
	static_assert(std::is_same_v<decltype(a), decltype(b)>, "values are of a different type");
	static_assert(is_comparable_v<decltype(a), decltype(b)>, "values can not be compared");

	return ( a < b ? a : b );
}

// Max template

template <typename T>
T	max(T& a, T& b)
{
	static_assert(std::is_same_v<decltype(a), decltype(b)>, "values are of a different type");
	static_assert(is_comparable_v<decltype(a), decltype(b)>, "values can not be compared");

	return ( a > b ? a : b );
}
