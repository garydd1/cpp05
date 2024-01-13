#include "BitcoinExchange.hpp"

int main (int argc, char** argv)
{
	BitcoinExchange exchange;
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}
	if (!exchange.readInput(argv[1]))
	{
		std::cout << "Error reading data from file " << argv[1] << std::endl;
		return 1;
	}
	return 0;
}
