#include "Intern.hpp"

//OCF
Intern::Intern()
{
	_forms[0] = "presidential pardon";
	_forms[1] = "robotomy request";
	_forms[2] = "shrubbery creation";
	_makeForm[0] = &Intern::makePresidentialPardonForm;
	_makeForm[1] = &Intern::makeRobotomyRequestForm;
	_makeForm[2] = &Intern::makeshrubberyCreationForm;
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& toCopy)
{
	*this = toCopy;
}

Intern& Intern::operator=(const Intern& toCopy)
{
	(void)toCopy;
	return (*this);
}

//Member function
AForm* Intern::makeForm(std::string formName, std::string target)
{
	AForm* form = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (formName == _forms[i])
			form = (this->*_makeForm[i])(target);
	}
	return (form);
}

AForm* Intern::makePresidentialPardonForm(std::string target)
{
	std::cout << "Intern creates " << target << " Presidential Pardon Form" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomyRequestForm(std::string target)
{
	std::cout << "Intern creates " << target << " Robotomy Form" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeshrubberyCreationForm(std::string target)
{
	std::cout << "Intern creates " << target << " shrubbery form" << std::endl;
	return (new shrubberyCreationForm(target));
}