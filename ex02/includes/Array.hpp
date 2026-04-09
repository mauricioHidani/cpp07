
#pragma once

#include <iostream>
#include <exception>

template<typename T> class Array {
private:
	unsigned int	_size;
	T*				_data;

	Array(void);

public:
	Array(const unsigned int& n);
	Array(const Array& other);
	virtual ~Array(void);

	unsigned int size(void) const;
	int indexOf(T& data) const;

	Array& operator=(const Array& other);
	T& operator[](unsigned int index);
	const T& operator[](const unsigned int index) const;

public:
	class IndexOutOfBoundsException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& instance);

#include "Array.tpp"
