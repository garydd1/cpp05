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
	argv++;
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

void PmergeMe::readArgsVect(int argc, char**argv)
{
	std::vector<int> numbers;
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int num;
		if (!(ss >> num))
		{
			std::cout << "Error: " << argv[i] << " is not a number" << std::endl;
			exit(1);
		}
		numbers.push_back(num);
	}

	//Check if there are repeated numbers
	//save a copy of the unsorted vector
	std::vector<int> unsorted = numbers;
	std::sort(numbers.begin(), numbers.end());
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end() - 1; it++)
	{
		if (*it == *(it + 1))
		{
			std::cout << "Error: " << *it << " is repeated" << std::endl;
			exit(1);
		}
	}
	//Save the pairs in a vector of pairs
	for (std::vector<int>::iterator it = unsorted.begin(); it != unsorted.end(); it++)
	{
		if (it + 1 == unsorted.end())
		{
			pairs.push_back(std::make_pair(*it, -1));
		}
		else
		{
			pairs.push_back(std::make_pair(*it, *(it + 1)));
			it++;
		}
	}
}

void PmergeMe::readArgsList(int argc, char** argv)
{
	std::list<int> numbers;
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int num;
		if (!(ss >> num))
		{
			std::cout << "Error: " << argv[i] << " is not a number" << std::endl;
			exit(1);
		}
		numbers.push_back(num);
	}

	//Check if there are repeated numbers
	//save a copy of the unsorted vector
	std::list<int> unsorted = numbers;
	std::list<int>::iterator it = numbers.begin();
    while (it != numbers.end())
    {
        std::list<int>::iterator next_it = it;
        ++next_it;
        if (next_it != numbers.end() && *it == *next_it)
        {
            std::cout << "Error: " << *it << " is repeated" << std::endl;
            exit(1);
        }
        ++it;
    }
	//Save the pairs in a vector of pairs
	for (it = unsorted.begin(); it != unsorted.end(); ++it)
    {
        std::list<int>::iterator next_it = it;
        ++next_it;
        if (next_it == unsorted.end())
        {
            pairsList.push_back(std::make_pair(*it, -1));
        }
        else
        {
            pairsList.push_back(std::make_pair(*it, *next_it));
            ++it; // Skip the next element as it's already paired
        }
    }
}

void PmergeMe::printVector()
{
	std::cout << "\n1. Split by pairs: \n" << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		std::cout << it->first << ", " << it->second << std::endl;
	}
	std::cout << std::endl;
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
			if (it->first < it->second)
			{
				_Main.push_back(it->second);
				_Pend.push_back(it->first);
			}
			else
			{
				_Main.push_back(it->first);
				_Pend.push_back(it->second);
			}
		}
	}


	//print Main vector
	std::cout << "2. Create main and pending vectors: \n" << std::endl;
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

std::vector<int>& PmergeMe::GetMain()
{
	return _Main;
}

std::vector<int>& PmergeMe::GetPend()
{
	return _Pend;
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

void PmergeMe::Merge(std::vector<int>& array, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	/* create temp arrays */
	std::vector<int> L;
	std::vector<int> R;

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L.push_back(array[left + i]);
	for (j = 0; j < n2; j++)
		R.push_back(array[mid + 1 + j]);

	/* Merge the temp arrays back into array[left..right]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = left; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}

void PmergeMe::MergeSortVector(std::vector<int>& array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		MergeSortVector(array, left, mid);
		MergeSortVector(array, mid + 1, right);

		// Merge the sorted halves
		Merge(array, left, mid, right);
	}
}

//INSERT MAIN AND PENDING VECTORS INTO THE MAIN VECTOR SORTED WITH INSERTION SORT
void PmergeMe::InsertVectors() {
	for (std::vector<int>::iterator pend_it = _Pend.begin(); pend_it != _Pend.end(); ++pend_it) {
		for (std::vector<int>::iterator main_it =_Main.begin(); main_it !=_Main.end(); ++main_it) {
			if (*main_it > *pend_it) {
			_Main.insert(main_it, *pend_it);
				break;
			}
			if ((main_it + 1) ==_Main.end()) {
			_Main.insert(_Main.end(), *pend_it);
				break;
			}
		}
	}
	std::cout << std::endl << "\nMerged vector: " <<std::endl;
	for (std::vector<int>::iterator it = _Main.begin(); it != _Main.end(); it++)
	{
		std::cout << *it << " ";
	}
}


//WITH LISTS

void PmergeMe::printList()
{
	std::cout << "\n1. Split by pairs: \n" << std::endl;
	for (std::list<std::pair<int, int> >::iterator it = pairsList.begin(); it != pairsList.end(); it++)
	{
		std::cout << it->first << ", " << it->second << std::endl;
	}
	std::cout << std::endl;
}

/**
 * @brief Iterates through the vector of pairs and inserts the numbers into the main set and the pending set
 * Main contains the higher number of the pair
 * Pending contains the lower number of the pair
 * If the pair only has one number, it is inserted into the main set
 */
void PmergeMe::splitLists()
{
	for (std::list<std::pair<int, int> >::iterator it = pairsList.begin(); it != pairsList.end(); it++)
	{
		if (it->second == -1)
		{
			_MainList.push_back(it->first);
		}
		else
		{
			if (it->first < it->second)
			{
				_MainList.push_back(it->second);
				_PendList.push_back(it->first);
			}
			else
			{
				_MainList.push_back(it->first);
				_PendList.push_back(it->second);
			}
		}
	}
	std::cout << "2. Create main and pending lists: \n" << std::endl;
	std::cout << "Main list: ";
	for (std::list<int>::iterator it = _MainList.begin(); it != _MainList.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	//print Pending vector
	std::cout << std::endl << "Pending list: ";
	for (std::list<int>::iterator it = _PendList.begin(); it != _PendList.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::list<int>& PmergeMe::GetMainList()
{
	return _MainList;
}

std::list<int>& PmergeMe::GetPendList()
{
	return _PendList;
}

void PmergeMe::MergeSortList(std::list<int>& array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		MergeSortList(array, left, mid);
		MergeSortList(array, mid + 1, right);

		// Merge the sorted halves
		MergeList(array, left, mid, right);
	}
}

void PmergeMe::MergeList(std::list<int>& array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* create temp arrays */
    std::list<int> L;
    std::list<int> R;

    /* Copy data to temp arrays L[] and R[] */
    std::list<int>::iterator it = array.begin();
    std::advance(it, left);
    for (int i = 0; i < n1; i++, it++)
        L.push_back(*it);

    for (int j = 0; j < n2; j++, it++)
        R.push_back(*it);

    /* Merge the temp arrays back into array[left..right]*/
    it = array.begin();
    std::advance(it, left);
    std::list<int>::iterator L_it = L.begin(), R_it = R.begin();
    while (L_it != L.end() && R_it != R.end()) {
        if (*L_it <= *R_it) {
            *it = *L_it;
            L_it++;
        } else {
            *it = *R_it;
            R_it++;
        }
        it++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (L_it != L.end()) {
        *it = *L_it;
        L_it++;
        it++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (R_it != R.end()) {
        *it = *R_it;
        R_it++;
        it++;
    }
}


void PmergeMe::InsertLists() {
    for (std::list<int>::iterator pend_it = _PendList.begin(); pend_it != _PendList.end(); ++pend_it) {
        bool inserted = false;
        for (std::list<int>::iterator main_it = _MainList.begin(); main_it != _MainList.end(); ++main_it) {
            if (*main_it > *pend_it) {
                _MainList.insert(main_it, *pend_it);
                inserted = true;
                break;
            }
            std::list<int>::iterator next_it = main_it;
            ++next_it;
            if (next_it == _MainList.end()) {
                _MainList.insert(_MainList.end(), *pend_it);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            // This handles the case where _PendList has elements greater than all elements in _MainList
            _MainList.push_back(*pend_it);
        }
    }
    std::cout << std::endl << "\nMerged list: " << std::endl;
    for (std::list<int>::iterator it = _MainList.begin(); it != _MainList.end(); it++) {
        std::cout << *it << " ";
    }
}


