#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& toCopy);
		BitcoinExchange& operator=(const BitcoinExchange& toCopy);

		bool readInput(std::string filename);
		bool readDataBase(std::string filename);
		void getValues(std::string date, double ammount);
		static void IsValidDate(std::string date);
		class InputException: public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		std::map<std::string, double> _dataBase;
		std::map<std::string, double> _dataInput;
		void _addData(std::string date, double value, bool flag = true);

};

#endif
