#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:

		~ScalarConverter();


		static void convert(std::string const &value);
		


	private: 

		ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &toCopy);
		ScalarConverter(ScalarConverter const &toCopy);
		ScalarConverter(std::string const &value);
};

bool isChar(std::string const &value);
bool isNum(std::string const &value);

#endif