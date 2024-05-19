#ifndef shrubberyCREATIONFORM_HPP
# define shrubberyCREATIONFORM_HPP
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class shrubberyCreationForm : public AForm 
{
	public:
	//OCF
	shrubberyCreationForm();
	~shrubberyCreationForm();
	shrubberyCreationForm(std::string target);
	shrubberyCreationForm(const shrubberyCreationForm& toCopy);
	shrubberyCreationForm& operator=(const shrubberyCreationForm& toCopy);

	//Virtual function override
	void execute(Bureaucrat const & executor) const;
	void action(Bureaucrat const & executor) const;

	private:

	std::string _target;
};

#endif