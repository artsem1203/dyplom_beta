#pragma once
#include <iostream>
#include <type_traits>

template <class T, class ...>
struct are_same : std::true_type {};

template<class T, class U, class ...TT>
struct are_same<T, U, TT...> : std::integral_constant<bool, std::is_same<T, U>{} 
	&& are_same<T, TT...>{} > {};

template <class ...>
struct are_integral : std::true_type {};

template<class T, class ...TT>
struct are_integral<T, TT...> : std::integral_constant<bool, std::is_integral<T>{}
	&& are_integral<TT...>{} > {};

template<typename... Args>
class VariadicTemplate {
public:
	static_assert(are_integral<Args...>{}, "Error: all values must be integral");
};
