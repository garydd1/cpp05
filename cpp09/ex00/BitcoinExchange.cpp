#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy)
{
	_dataExchange = toCopy._dataExchange;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& toCopy)
{
	_dataExchange = toCopy._dataExchange;
	return *this;
}

bool BitcoinExchange::readData(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error opening file " << filename << std::endl;
		return false;
	}
	std::string line;
	try
	{
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			std::string date;
			double value;

			if (line.find(',') == std::string::npos)
				throw BitcoinExchange::InputException();
			std::getline(ss, date, ',');
			if (!(ss >> value))
				throw BitcoinExchange::InputException();
			_addData(date, value);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	file.close();
	return true;
}

void BitcoinExchange::IsValidDate(std::String date)
{
	if (date.size != 10 || date[4] != '-' || date[7] != '-')
		throw BitcoinExchange::InputException();
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			throw BitcoinExchange::InputException();
	}
}

const char* BitcoinExchange::InputException::what() const throw()
{
	return("Invalid format in file");
}

void BitcoinExchange::_addData(std::string date, double value)
{
	this->_dataExchange[date] = value;
}

void BitcoinExchange::printValue(int n)
{
	std::map<std::string, double>::iterator it; 
	// for (it = this->_dataExchange.begin(); it != this->_dataExchange.end(); ++it)
	// {
	// 	n++;
	// 	std::cout <<it->first << "," << it->second << std::endl;
	// }
	n++;
	it = --_dataExchange.end();
	std::cout << (it->first) << std::endl;
}
