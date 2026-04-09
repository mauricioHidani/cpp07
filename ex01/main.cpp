
#include <iostream>
#include "iter.hpp"

void printTest(std::ostream &out, const int idx, const std::string tba)
{
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

int main(void)
{
	size_t index = 1;

	{ // TEST ==================================================================
		printTest(std::cout, index++, "Show string's array");
		std::string array[4] = {"42sp", "42fr", "42sv", "42tokyo"};
		iter<std::string>(array, 4, displayArray<std::string>);
		std::cout << std::endl;
	}

	{ // TEST ==================================================================
		printTest(std::cout, index++, "Show const string1s arrays");
		std::string array[4] = {"42SP", "42FR", "42SV", "42TOKYO"};
		iter<const std::string>(array, 4, displayArray<const std::string>);
		std::cout << std::endl;
	}

	{ // TEST ==================================================================
		printTest(std::cout, index++, "Show double's arrays");
		double array[4] = {42, 4, 2, 0};
		iter<double>(array, 4, displayArray<double>);
		std::cout << std::endl;
	}

	return 0;
}
