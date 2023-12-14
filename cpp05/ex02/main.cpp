#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat b1("JUAN", 150);
	b1<< std::cout;
	ShruberyCreationForm f1("wh");
	f1.execute(b1);	
	f1.beSigned(b1);
	b1.signForm(f1);
	f1.execute(b1);	
	b1.incrementGrade(149);
	b1.signForm(f1);
	b1.executeForm(f1);
	//ROBOTOMY
	RobotomyRequestForm f2("test2");
	f2.execute(b1);
	b1.signForm(f2);
	f2.execute(b1);
	//PRESIDENTIAL
	PresidentialPardonForm f3("test3");
	f3.execute(b1);
	b1.signForm(f3);
	f3.execute(b1);

	return (0);
}