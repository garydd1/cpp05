#include "Formm.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("Default"),
_isSigned(false),
_gradeSign(1),
_gradeExec(1)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string name, int grade2sign, int grade2exec): _name(name),
_gradeSign(grade2sign),
_gradeExec(grade2exec)
{
	_isSigned = false;
	if (grade2exec < 1 || grade2sign < 1)
		throw Form::GradeTooHighException();
	if (grade2exec > 150 || grade2sign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Param Form Constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form& toCopy): _name(toCopy._name),
_isSigned(false),
_gradeSign(toCopy._gradeSign),
_gradeExec(toCopy._gradeExec)
{
	std::cout << "Form Copy Constructor Called";
}

Form& Form::operator=(const Form& toCopy)
{
	if (this != &toCopy)
	{
		_isSigned = toCopy._isSigned;
	}
	return (*this);
}

std::string Form::getName(void)
{
	return(_name);
}

bool Form::getSignedStatus(void)
{
	return(_isSigned);
}

int Form::getGradeSign(void)
{
	return(_gradeSign);
}

int Form::getGradeExec(void)
{
	return(_gradeExec);
}

void Form::beSigned(Bureaucrat& bure)
{
	try
	{
		if (bure.getGrade() <= _gradeSign)
		{
			_isSigned = true;
			std::cout << "'"<< _name<<"' Signed with blood by: "
			<< bure.getName() << std::endl; 
		}
		else
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}


//FORM EXCEPTIONS
const char* Form::GradeTooHighException::what() const throw()
{
	return("Form: Grade too High! to sign ?");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Form: Grade too Low to sign !");
}

//Insertion Operator Overload
std::ostream& operator<<(std::ostream& cout, Form& toPrint)
{
	cout << "Form(Name: " << toPrint.getName()
	<< ", Grade to Execute: " << toPrint.getGradeExec()
	<< ", Grade to Sign: " << toPrint.getGradeSign()
	<< ", Signed status: " << toPrint.getSignedStatus() << ") " << std::endl;	
	return(cout);
}

