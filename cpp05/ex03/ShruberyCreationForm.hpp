#ifndef SHRUBERYCREATIONFORM_HPP
# define SHRUBERYCREATIONFORM_HPP
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShruberyCreationForm : public AForm 
{
	public:
	//OCF
	ShruberyCreationForm();
	~ShruberyCreationForm();
	ShruberyCreationForm(std::string target);
	ShruberyCreationForm(const ShruberyCreationForm& toCopy);
	ShruberyCreationForm& operator=(const ShruberyCreationForm& toCopy);

	//Virtual function override
	void execute(Bureaucrat const & executor) const;
	void action(Bureaucrat const & executor) const;

	private:

	std::string _target;
};

#endif