#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // For srand
#include <ctime>   // For time

int main(void)
{
	srand(time(NULL));
	Base* base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}