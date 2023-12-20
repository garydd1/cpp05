#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:

		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter const &toCopy);

		static void convert(std::string const &value);
		


	private: 

		ScalarConverter();
		// ScalarConverter(std::string const &value);
		// ScalarConverter(ScalarConverter const &toCopy);
};

bool isChar(std::string const &value);
bool isNum(std::string const &value);

#endif