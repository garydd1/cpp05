#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
	public:
	//OCF
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& toCopy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& toCopy);

	//Virtual function override
	void execute(Bureaucrat const & executor) const;
	void action(Bureaucrat const & executor) const;

	private:

	std::string _target;
	bool		_executed;
};
#endif