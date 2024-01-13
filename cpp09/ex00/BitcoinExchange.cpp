#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy)
{
	_dataBase = toCopy._dataBase;
	_dataInput = toCopy._dataInput;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& toCopy)
{
	_dataBase = toCopy._dataBase;
	_dataInput = toCopy._dataInput;
	return *this;
}

bool BitcoinExchange::readInput(std::string filename)
{
	if (!readDataBase("database.csv"))
		return true;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error opening file " << filename << std::endl;
		return false;
	}
	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
	{
		// The file is empty
		std::cout << "Error: file is empty " << filename << std::endl;
		return false;
	}
	file.seekg(0, std::ios::beg);
	std::string line;
	try
	{
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			std::string date;
			double value;

			if (line.find('|') == std::string::npos)
			{
				std::cout << "Error: invalid format: " << line << std::endl;
				continue;
			}
			if (line.find("date") != std::string::npos)
				continue;
			std::getline(ss, date, '|');
			if (!(ss >> value))
			{
				std::cout << "Error reading value: " << line << std::endl;
				continue;
			}
			if (value < 0 || value > 1000)
			{
				if (value < 0)
					std::cout << "Error: value is negative: " << line << std::endl;
				else
					std::cout << "Error: value is too high: " << line << std::endl;
				continue;
			}
			_addData(date, value, false);
			getValues(date, value);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	file.close();
	return true;
}

void BitcoinExchange::getValues(std::string date, double ammount)
{
	std::cout << date << "=>" << ammount << " = ";
	std::map<std::string, double>::iterator it = this->_dataBase.lower_bound(date);
	if(it != this->_dataBase.begin() && (it == this->_dataBase.end() || date != it->first))
		it--;
	if (it == this->_dataBase.begin() && date != it->first)
	{
		std::cout << "closest date not found, date too early: " << date << "=>" << ammount << std::endl;
		return;
	}
	if (it != this->_dataBase.end())
		std::cout << ammount * it->second << std::endl;

}

bool BitcoinExchange::readDataBase(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error opening file " << filename << std::endl;
		return false;
	}
	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
	{
		std::cout << "Error: Database file is empty " << filename << std::endl;
		return false;
	}
	file.seekg(0, std::ios::beg);
	std::string line;
	try
	{
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			std::string date;
			double value;

			if (line.find(',') == std::string::npos)
			{
				std::cout << "Error: invalid format: " << line << std::endl;
				continue;
			}
			if (line.find("date") != std::string::npos)
				continue;
			std::getline(ss, date, ',');
			if (!(ss >> value))
			{
				std::cout << "Error reading value: " << line << std::endl;
				continue;
			}
			if (value < 0)
			{
				if (value < 0)
					std::cout << "Error: value is negative: " << line << std::endl;
				else
					std::cout << "Error: value is too high: " << line << std::endl;
				continue;
			}
			_addData(date, value, true);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	file.close();
	return true;
}

void BitcoinExchange::IsValidDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: invalid date format: " << date << std::endl;
		throw BitcoinExchange::InputException();
	}
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
		{
			std::cout << "Error: invalid date format: " << date << std::endl;
			throw BitcoinExchange::InputException();
		}
	}
}

const char* BitcoinExchange::InputException::what() const throw()
{
	return("Invalid format in file");
}

void BitcoinExchange::_addData(std::string date, double value, bool flag)
{
	if (flag)
		this->_dataBase[date] = value;
	else
		this->_dataInput[date] = value;
}
