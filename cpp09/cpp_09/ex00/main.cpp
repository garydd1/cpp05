#include "BitcoinExchange.hpp"

int main (int argc, char** argv)
{
	BitcoinExchange exchange;
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}
	if (!exchange.readData(argv[1]))
	{
		std::cout << "Error reading data from file " << argv[1] << std::endl;
		return 1;
	}
	exchange.printValue(2);
	// std::cout << "The average value of Bitcoin in the last 30 days is " << exchange.getAverage() << std::endl;
	// std::cout << "The maximum value of Bitcoin in the last 30 days is " << exchange.getMax() << std::endl;
	// std::cout << "The minimum value of Bitcoin in the last 30 days is " << exchange.getMin() << std::endl;
	// std::cout << "The standard deviation of Bitcoin in the last 30 days is " << exchange.getStdDev() << std::endl;
	return 0;
}