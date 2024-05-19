#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 75, 45)
{
	_executed = false;
	std::cout <<"Robotomy default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 75, 45)
{
	_target = target;
	_executed = false;
	std::cout<<"Robotomy Param constructor Called."<<std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
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

void RobotomyRequestForm::action(Bureaucrat const & executor) const 
{
	srand(time(0));
	std::cout <<BLUE "...Drilling noises..." RST << std::endl;
	executor.getName();
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " has failed to be robotomized." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Destructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy): AForm("Robotomy", 75, 45)
{
	_target = toCopy._target;
	_executed = toCopy._executed;
	std::cout << "Robotomy Copy Constructor Called"<< std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& toCopy)
{
	if (this != &toCopy)
	{
		_target = toCopy._target;
	}
	return(*this);
	std::cout << "Robotomy Operator = overload Called" << std::endl;
}
