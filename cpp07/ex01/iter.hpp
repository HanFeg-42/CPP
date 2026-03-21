#pragma once

template<typename T>
void print(const T& value)
{
	std::cout << value << std::endl;
}

template<typename T>
void iter(T* arr, const int size, void (*func)(const T&))
{
	for (int i = 0; i < size; i++)
		func(arr[i]);
}