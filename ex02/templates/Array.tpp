
#include <iostream>

template<typename T>
Array<T>::Array(void)
	:	_size(0), 
		_data(NULL) {
}

template<typename T>
Array<T>::Array(const unsigned int& n)
	:	_size(n),
		_data(new T[n]) {
}

template<typename T>
Array<T>::Array(const Array<T>& other)
	:	_size(other.size()), 
		_data(new T[other.size()]) {
	for (unsigned int i = 0; i < size(); i++)
		_data[i] = other[i];
}

template<typename T>
Array<T>::~Array(void) {
	delete[] _data;
}

template<typename T>
unsigned int Array<T>::size(void) const {
	return _size;
}

template<typename T>
int Array<T>::indexOf(T& data) const {
	for (unsigned int i = 0; i < size(); i++)
		if (_data[i] == data)
			return i;
	return -1;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] _data;

		_size = other.size();
		_data = new T[other.size()];
		for (unsigned int i = 0; i < size(); i++)
			_data[i] = other[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= size())
		throw IndexOutOfBoundsException();
	return _data[index];
}

template<typename T>
const T& Array<T>::operator[](const unsigned int index) const {
	if (index >= size())
		throw IndexOutOfBoundsException();
	return _data[index];
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& instance) {
	out << "Array: {";
	for (unsigned int i = 0; i < instance.size(); i++) {
		out << instance[i];
		if (i < instance.size() - 1)
			out << ", ";
	}
	out << "}";
	return out;
}

template<typename T> const char* Array<T>::IndexOutOfBoundsException::what() const throw() {
	return "The requested index is outside the valid limits of the container";
}
