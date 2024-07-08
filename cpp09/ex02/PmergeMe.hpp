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
#include <set>
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"


class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& toCopy);
		PmergeMe& operator=(const PmergeMe& toCopy);
		void readArgsVect(int argc, char** argv);
		void splitVects();
		void MergeVects();
		void printVector();
		void MergeSortVector(std::vector<int>& array, int left, int right);
		void InsertVectors();
		void Merge(std::vector<int>& array, int left, int mid, int right);
		void readArgsList(int argc, char** argv);
		void printList();
		void splitLists();
		void MergeSortList(std::list<int>& array, int left, int right);
		void MergeList(std::list<int>& array, int left, int mid, int right);
		void InsertLists();

		
		std::vector<int>& GetMain();
		std::vector<int>& GetPend();
		std::list<int>& GetMainList();
		std::list<int>& GetPendList();

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