#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
	public:
	//OCF
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& toCopy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& toCopy);

	//Virtual function override
	void execute(Bureaucrat const & executor) const;
	void action(Bureaucrat const & executor) const;

	private:

	std::string _target;
	bool		_executed;
};
#endif