#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("PABLO", 1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat b1("JUAN", 4);
	// b1<< std::cout;
	std::cout << b1;
	b1.incrementGrade(3);
	// b1<< std::cout;
	std::cout << b1;
	b1.incrementGrade(3);
	// b1<< std::cout;
	std::cout << b1;
	b1.decrementGrade(148);
	// b1<< std::cout;
	std::cout << b1;
	b1.decrementGrade(148);
	// b1<< std::cout;
	std::cout << b1;
	return (0);
}