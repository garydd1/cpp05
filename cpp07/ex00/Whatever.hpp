#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T>
T max(T const &a, T const &b)
{
	return (a > b ? a : b);
}
template <typename T>
T min(T const &a, T const &b)
{
	return (a < b ? a : b);
}
template <typename T>
void swap(T &a, T &b)
{
	std::cout << "swap" << std::endl;
	T tmp = a;
	a = b;
	b = tmp;
}


#endif