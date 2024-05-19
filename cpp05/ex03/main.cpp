#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat b1("JUAN", 150);
	//Intern
	Intern intern;
	AForm* f1 = intern.makeForm("shrubbery creation", "wh");
	f1->execute(b1);
	f1->beSigned(b1);
	b1.incrementGrade(149);
	b1.signForm(*f1);
	b1.executeForm(*f1);
	return (0);
}