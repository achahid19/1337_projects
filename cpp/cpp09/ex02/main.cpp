#include "PmergeMe.hpp"

int main(int ac, char **av) {
    std::vector<int> lst;
    std::deque<int>  d;

	if (ac < 3) {
		std::cerr << "Error: Invalid args!" << std::endl;
		return 0;
	}
	av++;
	while(*av != NULL) {
		lst.push_back(std::atoi(*av));
        d.push_back(std::atoi(*av));
		av++;
	}
	
    std::cout << "Before: ";
    for (std::vector<int>::iterator num = lst.begin(); num != lst.end(); num++) {
        std::cout << *num << " ";
    }
    std::cout << std::endl;

	PmergeMe    obj;
    double      vTimer, dTimer;
    clock_t     start, end;

    start = clock();
    std::vector<int> sortedArr = obj.fordJohnsonSort(lst);
    end = clock();
    vTimer = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    
    start = clock();
    std::deque<int>  sortedArrDeque = obj.fordJohnsonSort(d);
    end = clock();
    dTimer = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    
    std::cout << "After: ";
	for (std::vector<int>::iterator num = sortedArr.begin(); num != sortedArr.end(); num++) {
        std::cout << *num << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of : " << lst.size() << " elements ";
    std::cout << "with std::vector : " << vTimer << " us" << std::endl;
    std::cout << "Time to process a range of : " << d.size() << " elements ";
    std::cout << "with std::duque : " << dTimer << " us" << std::endl;
    
    return 0;
}
