#pragma once

template<typename T>
void print(const T& value)
{
	std::cout << value << " ";
}

template<typename T>
void iter(T* arr, const int size, void (*func)(T&))
{
	for (int i = 0; i < size; i++)
		func(arr[i]);
}
