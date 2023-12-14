#ifndef BUREAUCRAT_HPP	
# define BUREAUCRAT_HPP

class Form;
#include <iostream>

class Bureaucrat
{	
	public:
	//Nested Exceptions
	class GradetooHighException : public std::exception 
	{
		public:
			const char * what() const throw();
	};
	class GradetooLowException : public std::exception
	{
		public:
			const char * what() const throw();
	};
	//OCF
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& original);
	Bureaucrat& operator=(const Bureaucrat& toCopy);

	//Mandatory part
	std::string		getName() const;
	int				getGrade() const;
	void			incrementGrade(int toInc);
	void			decrementGrade(int toDec);
	std::ostream&	operator<<(std::ostream& cout);
	void			signForm(Form& f);

	private:

	const std::string 	_name;
	int					_grade;

};

// std::ostream& operator<<(std::ostream& cout, Bureaucrat& toPrint);


#endif