#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	srand(time(NULL));
	Base* base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}