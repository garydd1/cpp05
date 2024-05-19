#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat b1("JUAN", 4);
	b1<< std::cout;
	Form f1("build a Castle", 2, 1);
	// f1.beSigned(b1);
	b1.signForm(f1);
	b1.incrementGrade(2);
	std::cout<<f1; 
	b1.signForm(f1);
	// f1.beSigned(b1);
	return (0);
}