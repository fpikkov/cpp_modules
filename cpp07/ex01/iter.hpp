#pragma once

#include <iostream>

template <typename T, typename = void>
struct is_multipliable : std::false_type {};

template <typename T>
struct is_multipliable <T, std::void_t<
	decltype(std::declval<T>() * std::declval<T>())
>> : std::true_type {};

template <typename T>
inline constexpr bool is_multipliable_v = is_multipliable<T>::value;

template <typename T>
void	square(T& a)
{
	static_assert(is_multipliable_v<T>, "Value cannot be multiplied by itself");
	a *= a;
}

template <typename T>
void	print(T& a) { std::cout << " " << a << " "; }

template <typename T>
void	iter(T* array, size_t size, void (*func)(T&))
{
	for (size_t idx = 0; idx < size; ++idx)
		func(array[idx]);
}
