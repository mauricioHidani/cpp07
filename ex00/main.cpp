
#include <iostream>
#include "whatever.hpp"

template<typename T>
void printStatus(std::ostream& out, const std::string& target, 
				 const T& s1, const T& s2) {
	out << target << ": ("
		<< "value_1: " << s1
		<< ", value_2: " << s2
		<< ")" << std::endl;
}

int main(void) {
	int	a = 22;
	int b = 42;

	std::cout << "swap test" << std::endl;
	printStatus(std::cout, "before", a, b);
	::swap<int>(a, b);
	printStatus(std::cout, "after", a, b);
	std::cout << std::endl;

	printStatus(std::cout, "min test", a, b);
	int min = ::min(a, b);
	std::cout << "min: " << min << std::endl;
	std::cout << std::endl;
	
	printStatus(std::cout, "max test", a, b);
	int max = ::max(a, b);
	std::cout << "max: " << max << std::endl;
	std::cout << std::endl;

	return 0;
}
