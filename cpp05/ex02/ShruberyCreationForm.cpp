#include "AForm.hpp"
#include "ShruberyCreationForm.hpp"
#include <fstream>

ShruberyCreationForm::ShruberyCreationForm() : AForm("Default", 145, 137)
{
	_target = _target;
	std::cout <<"Shrubery default Constructor Called" << std::endl;
}

ShruberyCreationForm::ShruberyCreationForm(std::string target): AForm("Shrubery", 145, 137)
{
	_target = target;
	std::cout<<"Shrubery Param constructor Called."<<std::endl;
}

void ShruberyCreationForm::execute(Bureaucrat const & executor) const
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

void ShruberyCreationForm::action(Bureaucrat const & executor) const 
{
		std::string outputFileName = _target; 
		outputFileName += "_shrubery.txt";
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

ShruberyCreationForm::~ShruberyCreationForm()
{
	std::cout << "Shrubery Destructor Called" << std::endl;
}

ShruberyCreationForm::ShruberyCreationForm(const ShruberyCreationForm& toCopy): AForm("Shrubery", 145, 137)
{
	_target = toCopy._target;
	std::cout << "Shrubery Copy Constructor Called"<< std::endl;
}

ShruberyCreationForm& ShruberyCreationForm::operator=(const ShruberyCreationForm& toCopy)
{
	if (this != &toCopy)
	{
		_target = toCopy._target;
	}
	return(*this);
	std::cout << "Shrubery Operator = overload Called" << std::endl;
}
