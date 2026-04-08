
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
	{
		std::cout << "TEST 1" << std::endl;
		int	a = 2;
		int	b = 3;
	
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "TEST 2" << std::endl;
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
	}

	return 0;
}
