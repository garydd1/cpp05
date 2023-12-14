#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class AForm
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

	class UnsignedFormException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	//OCF Constructors
	AForm(void);
	AForm(std::string name, int grade2sign, int grade2exec);
	virtual ~AForm(void);
	AForm(const AForm& toCopy);
	AForm& operator=(const AForm& toCopy);

	//Getters
	std::string			getName(void) const;
	bool				getSignedStatus(void);
	int					getGradeSign(void);
	int					getGradeExec(void);

	//Mandatory Additional member functions
	void				beSigned(Bureaucrat& bure);
	
	//Abstract part
	virtual void execute(Bureaucrat const & executor) const = 0; 
	virtual void action(Bureaucrat const & executor) const = 0; 
	bool	checkToExec(Bureaucrat const & exec, AForm const & f) const;


	private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExec;
};

//Insertion operator overload
std::ostream& operator<<(std::ostream& cout, AForm& toPrint);
#endif