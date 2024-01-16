#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe pm(argc, argv);
	// pm.pairMe();
	pm.printVector();
	pm.splitVects();
	pm.MergeVects();
	return 0;
}