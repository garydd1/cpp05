#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 75, 45)
{
	_executed = false;
	std::cout <<"PresidentialPardon default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardon", 75, 45)
{
	_target = target;
	_executed = false;
	std::cout<<"PresidentialPardon Param constructor Called."<<std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try 
	{
		checkToExec(executor, *this);
		action(executor);
	}catch(std::exception& e)
	{
		std::cout<< e.what() << '\n';
	}
}

void PresidentialPardonForm::action(Bureaucrat const & executor) const 
{
	executor.getName();
	std::cout <<RED << _target << " has been pardoned by Zaphod Beeblebrox." RST << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardon Destructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy): AForm("PresidentialPardon", 75, 45)
{
	_target = toCopy._target;
	_executed = toCopy._executed;
	std::cout << "PresidentialPardon Copy Constructor Called"<< std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy)
{
	if (this != &toCopy)
	{
		_target = toCopy._target;
	}
	return(*this);
	std::cout << "PresidentialPardon Operator = overload Called" << std::endl;
}
