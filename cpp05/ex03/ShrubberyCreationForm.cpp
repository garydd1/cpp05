#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

shrubberyCreationForm::shrubberyCreationForm() : AForm("Default", 145, 137)
{
	std::cout <<"shrubbery default Constructor Called" << std::endl;
}

shrubberyCreationForm::shrubberyCreationForm(std::string target): AForm("shrubbery", 145, 137)
{
	_target = target;
	std::cout<<"shrubbery Param constructor Called."<<std::endl;
}

void shrubberyCreationForm::execute(Bureaucrat const & executor) const
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

void shrubberyCreationForm::action(Bureaucrat const & executor) const 
{
		std::string outputFileName = _target; 
		outputFileName += "_shrubbery.txt";
		std::ofstream outputFile(outputFileName.c_str());
		if (!outputFile.is_open()) {
			std::cerr << "Error opening the file." << std::endl;
		}

		outputFile << "    *\n";
		outputFile << "   / \\\n";
		outputFile << "  /   \\\n";
		outputFile << " /     \\\n";
		outputFile << "/  ___  \\\n";
		outputFile << "\nSigned by: " << executor.getName()<<std::endl;
		outputFile.close();
}

shrubberyCreationForm::~shrubberyCreationForm()
{
	std::cout << "shrubbery Destructor Called" << std::endl;
}

shrubberyCreationForm::shrubberyCreationForm(const shrubberyCreationForm& toCopy): AForm("shrubbery", 145, 137)
{
	_target = toCopy._target;
	std::cout << "shrubbery Copy Constructor Called"<< std::endl;
}

shrubberyCreationForm& shrubberyCreationForm::operator=(const shrubberyCreationForm& toCopy)
{
	if (this != &toCopy)
	{
		_target = toCopy._target;
	}
	return(*this);
	std::cout << "shrubbery Operator = overload Called" << std::endl;
}
