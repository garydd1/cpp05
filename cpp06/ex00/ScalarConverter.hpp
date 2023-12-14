#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:

		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter const &toCopy);

		static std::string convert(std::string const &value);
		


	private: 

		ScalarConverter();
		ScalarConverter(std::string const &value);
		ScalarConverter(ScalarConverter const &toCopy);
};


#endif SCALARCONVERTER_HPP