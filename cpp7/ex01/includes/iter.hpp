#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstring>
#include <cctype>

template <typename T>
void iter(T *array, size_t len, void (*f)( T &))
{
	if (!f || !array)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

#endif