#ifndef FORMM_HPP
#define FORMM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
	public:

	//Nested Exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	//OCF Constructors
	Form(void);
	Form(std::string name, int grade2sign, int grade2exec);
	~Form(void);
	Form(const Form& toCopy);
	Form& operator=(const Form& toCopy);

	//Getters
	std::string			getName(void);
	bool				getSignedStatus(void);
	int					getGradeSign(void);
	int					getGradeExec(void);

	//Mandatory Additional member functions
	void				beSigned(Bureaucrat& bure);
	



	private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExec;
};

//Insertion operator overload
std::ostream& operator<<(std::ostream& cout, Form& toPrint);
#endif