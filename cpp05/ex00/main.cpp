#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1("JUAN", 4);
	b1<< std::cout;
	b1.incrementGrade(3);
	b1<< std::cout;
	b1.incrementGrade(3);
	b1<< std::cout;
	b1.decrementGrade(148);
	b1<< std::cout;
	b1.decrementGrade(148);
	b1<< std::cout;
	return (0);
}