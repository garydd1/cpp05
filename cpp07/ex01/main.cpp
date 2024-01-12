#include "iter.hpp"

void print(const int& i) {
	std::cout << i << ' ';
}

void print_string(const std::string& s) {
	std::cout << s << ' ';
}

int main (void) {
	int int_array[5] = {0, 1, 2, 3, 4};
	std::string string_array[5] = {"zero", "one", "two", "three", "four"};

	std::cout << "int_array: ";
	iter(int_array, 5, print);
	std::cout << std::endl;

	std::cout << "string_array: ";
	iter(string_array, 5, print_string);
	std::cout << std::endl;

	return 0;
}