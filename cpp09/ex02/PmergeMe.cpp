#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cout << " PLEASE ENTER A LIST OF NUMBERS" << std::endl;
		exit(1);
	}
	for (int i = 1; i < argc; i += 2)
	{
		std::stringstream ss1(argv[i]);
		int num1;
		if (!(ss1 >> num1))
		{
			std::cout << "Error: " << argv[i] << " is not a number" << std::endl;
			exit(1);
		}
		//check if it is repeated
		

		if (i + 1 < argc)
		{
			std::stringstream ss2(argv[i + 1]);
			int num2;
			if (!(ss2 >> num2))
			{
				std::cout << "Error: " << argv[i + 1] << " is not a number" << std::endl;
				exit(1);
			}
			if (num1 < num2)
			{
				pairsList.push_back(std::make_pair(num1, num2));
				pairs.push_back(std::make_pair(num1, num2));
			}
			else
			{
				pairsList.push_back(std::make_pair(num2, num1));
				pairs.push_back(std::make_pair(num2, num1));
			}
		}
		else
		{
			pairs.push_back(std::make_pair(num1, -1));
		}
}
}

PmergeMe::PmergeMe(const PmergeMe& toCopy)
{
	*this = toCopy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& toCopy)
{
	if (this != &toCopy)
	{
		_Main = toCopy._Main;
		_Pend = toCopy._Pend;
		_result = toCopy._result;
		this->pairs = toCopy.pairs;
	}
	return *this;
}

void PmergeMe::printVector()
{
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

/**
 * @brief Iterates through the vector of pairs and inserts the numbers into the main set and the pending set
 * Main contains the higher number of the pair
 * Pending contains the lower number of the pair
 * If the pair only has one number, it is inserted into the main set
 */
void PmergeMe::splitVects()
{
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->second == -1)
		{
			_Main.push_back(it->first);
		}
		else
		{
			_Main.push_back(it->second);
			_Pend.push_back(it->first);
		}
	}

	//sort the vectors
	std::sort(_Main.begin(), _Main.end());
	std::sort(_Pend.begin(), _Pend.end());

	//print Main vector
	std::cout << "Main vector: ";
	for (std::vector<int>::iterator it = _Main.begin(); it != _Main.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	//print Pending vector
	std::cout << std::endl << "Pending vector: ";
	for (std::vector<int>::iterator it = _Pend.begin(); it != _Pend.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/**
 * @brief Merges the two vectors into one sorted vector
 * 
 */
void PmergeMe::MergeVects()
{
	std::vector<int>::iterator it1 = _Main.begin();
	std::vector<int>::iterator it2 = _Pend.begin();
	while (it1 != _Main.end() && it2 != _Pend.end())
	{
		if (*it1 < *it2)
		{
			_result.push_back(*it1);
			it1++;
		}
		else
		{
			_result.push_back(*it2);
			it2++;
		}
	}
	while (it1 != _Main.end())
	{
		_result.push_back(*it1);
		it1++;
	}
	while (it2 != _Pend.end())
	{
		_result.push_back(*it2);
		it2++;
	}
	std::cout << std::endl << "Merged vector: ";
	for (std::vector<int>::iterator it = _result.begin(); it != _result.end(); it++)
	{
		std::cout << *it << " ";
	}
}

//WITH LISTS
