#include "RPN.hpp"

int main (int arg, char** argv)
{
	// if (arg < 4 || arg > 10)
	// {
	// 	std::cout << "invalid number of arguments" << std::endl;
	// 	return 1;
	// }
	Rpn a(arg, argv);
	a.process(arg, argv);
	return (0);
}
