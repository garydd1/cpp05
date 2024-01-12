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

		bool readData(std::string filename);
		void printValue(int n);
		static void IsValidDate(std::string date);
		class InputException: public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		std::map<std::string, double> _dataExchange;
		void _addData(std::string date, double value);

};

#endif
