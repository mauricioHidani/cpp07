
#pragma once

#include <iostream>

template<typename T, typename F>
void iter(T* array, const size_t size, F func) {
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

template<typename V>
void displayArrayConst(const V& value) {
	std::cout << value << std::endl;
}

template<typename V>
void displayArray(V& value) {
	std::cout << value << std::endl;
}
