
#include <iostream>
#include "Array.hpp"

void printTest(std::ostream& out, const int idx, const std::string tba) {
	out << "test " << idx << " ";
	for (int i = 0; i < 73; i++)
		out << "=";
	out << std::endl;
	out << tba;
	out << std::endl;
	for (int i = 0; i < 80; i++)
		out << ".";
	out << std::endl;
}

int main(void) {
	size_t	index = 1;

	{ // TEST ==================================================================
		printTest(std::cout, index++,
			"Testing different types"
		);

		Array<int> intArray(3);
		for (unsigned int i = 0; i < intArray.size(); i++)
			intArray[i] = i + 1;
		std::cout << intArray << std::endl;

		Array<std::string> strArray(3);
		strArray[0] = "42sp";
		strArray[1] = "42fr";
		strArray[2] = "42tokyo";
		std::cout << strArray << std::endl;

		Array<double>* dobArray = new Array<double>(3);
		for (unsigned int i = 0; i < dobArray->size(); i++)
			(*dobArray)[i] = 0.42 * i;
		std::cout << *dobArray << std::endl;

		delete dobArray;
		std::cout << std::endl;
	}

	{ // TEST ==================================================================
		printTest(std::cout, index++,
			"Testing index out of bounds"
		);

		Array<std::string>* schools = new Array<std::string>(3);
		(*schools)[0] = "42 sao paulo";
		(*schools)[1] = "42 paris";
		(*schools)[2] = "42 tokyo";

		try {
			std::cout << "Try access index -1" << std::endl;
			std::cout << (*schools)[-1] << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "Try access index 3, when the array only has indices from 0 to 2" << std::endl;
			std::cout << (*schools)[3] << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		delete schools;
		std::cout << std::endl;
	}

	{ // TEST ==================================================================
		printTest(std::cout, index++,
			"Testing assignment and copy builder"
		);

		Array<int>* original = new Array<int>(4);
		for (unsigned int i = 0; i < original->size(); i++)
			(*original)[i] = i * 42;
		
		Array<int> copy(*original);
		Array<int> assignment = copy;

		std::cout << "Original " << *original << std::endl;
		std::cout << "Copy " << copy << std::endl;
		std::cout << "Assignment " << assignment << std::endl;

		delete original;
		std::cout << std::endl;
	}

	return 0;
}
