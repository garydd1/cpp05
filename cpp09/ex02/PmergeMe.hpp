#ifndef PMEGERME_HPP
#define PMEGERME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <list>
#include <map>
#include <unordered_map>
#include <set>


class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& toCopy);
		PmergeMe& operator=(const PmergeMe& toCopy);
		void splitVects();
		void MergeVects();
		void printVector();
	private:
		std::vector<int> _Main;
		std::vector<int> _Pend;
		std::vector<int> _result;
		std::vector<std::pair<int, int> > pairs;

		//The same but with lists
		std::list<int> _MainList;
		std::list<int> _PendList;
		std::list<int> _resultList;
		std::list<std::pair<int, int> > pairsList;

		

};


#endif