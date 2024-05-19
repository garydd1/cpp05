#include "ScalarConverter.hpp"
#include <iomanip>
#include <sstream>

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &toCopy)
{
	(void)toCopy;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &toCopy)
{
	(void)toCopy;
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

void ScalarConverter::convert(std::string const &value)
{
	//Convert to char
	char c;
	int i;
	// float f;
	// double d;
	if (isChar(value))
	{
		if (value.length() > 1)
			c = static_cast<char>(atoi(value.c_str()));
		else
			c = value[0];
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else if (!isChar(value))
	{
		if (value.length() > 1)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		// std::cout << "int: " << atoi(value.c_str()) << std::endl;
		
	}
	//Convert to int
	if (isNum(value) && value != "nan" && value != "nanf" && value != "-inf" && value != "+inf" && value != "-inff" && value != "+inff") 
	{
		i = atoi(value.c_str());
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(atof(value.c_str())) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << atof(value.c_str()) << std::endl;
	}else if (isNum(value) && (value == "nan" || value == "nanf" || value == "-inf" || value == "+inf" || value == "-inff" || value == "+inff"))
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(atof(value.c_str())) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << atof(value.c_str()) << std::endl;
	} else if (!isNum(value))
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

bool isChar(std::string const &value)
{
	if (value.length() == 1 && isalpha(value[0]) && std::isprint(value[0]))
		return true;
	if (atoi(value.c_str()) >= 32 && atoi(value.c_str()) <= 127)
		return true;
	return false;
}

bool isNum(std::string const &value)
{
	std::string copy = value;
	if (!copy.empty() && copy.back() == 'f') {
		copy.pop_back();  // Remove the 'f' at the end if it exists
	}
	std::istringstream iss(copy);
	double i;
	
	return (iss >> std::noskipws >> i && iss.eof());
}