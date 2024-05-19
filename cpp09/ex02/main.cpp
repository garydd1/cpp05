#include "PmergeMe.hpp"
#include <ctime>


int main(int argc, char** argv)
{
	PmergeMe pm(argc, argv);
	
	// VECTORS
	std::clock_t start = clock();
	pm.readArgsVect(argc, argv);
	pm.printVector();
	pm.splitVects();
	pm.MergeSortVector(pm.GetMain(), 0, pm.GetMain().size() - 1);
	std::cout << "\n3. Recursively sort the Main Vector: \n" << std::endl;
	std::cout << "Main vector: ";
	for (size_t i = 0; i < pm.GetMain().size(); ++i)
	{
		std::cout << pm.GetMain()[i] << " ";
	}
	std::cout << "\nPending vector: ";
	for (size_t i = 0; i < pm.GetPend().size(); ++i)
	{
		std::cout << pm.GetPend()[i] << " ";
	}
	std::cout << "\n\n4. Use Insertion Sort to insert the Pending Vector into the Main Vector:";
	pm.InsertVectors();
	std::clock_t stop = std::clock();
	double elapsed = (stop - start) / static_cast<double>(CLOCKS_PER_SEC);
	std::cout << "\n\n"GREEN"Elapsed time by VECTORS: " << std::fixed << elapsed << " seconds"RESET << std::endl;
	//END VECTORS
	// LISTS
	start = clock();
	pm.readArgsList(argc, argv);
	pm.printList();
	pm.splitLists();
	pm.MergeSortList(pm.GetMainList(), 0, pm.GetMainList().size() - 1);
	std::cout << "\n3. Recursively sort the Main List: \n" << std::endl;
	std::cout << "Main list: ";
	for (std::list<int>::iterator it = pm.GetMainList().begin(); it != pm.GetMainList().end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\nPending list: ";
	for (std::list<int>::iterator it = pm.GetPendList().begin(); it != pm.GetPendList().end(); it++)
	{
		std::cout << *it << " ";
	}
	pm.InsertLists();
	stop = std::clock();
	elapsed = (stop - start) / static_cast<double>(CLOCKS_PER_SEC);
	std::cout << "\n\n"GREEN"Elapsed time by LISTS: " << std::fixed << elapsed << " seconds"RESET << std::endl;
	// //END LISTS
	return 0;
}
