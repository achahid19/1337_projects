#include "PmergeMe.hpp"

int main(int ac, char **av) {
    std::list<int> lst;

	if (ac < 3) {
		std::cerr << "Error: Invalid args!" << std::endl;
		return 0;
	}
	av++;
	while(*av != NULL) {
		lst.push_back(std::atoi(*av));
		av++;
	}
	
    std::cout << "Original list: ";
    for (std::list<int>::iterator num = lst.begin(); num != lst.end(); num++) {
        std::cout << *num << " ";
    }
    std::cout << std::endl;

	PmergeMe obj;

    std::deque<int> sortedArr = obj.fordJohnsonSort(lst);

    std::cout << "Sorted array: ";
	for (std::deque<int>::iterator num = sortedArr.begin(); num != sortedArr.end(); num++) {
        std::cout << *num << " ";
    }
    std::cout << std::endl;

    return 0;
}
