#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <deque>
#include <cstdlib>
#include <vector>
#include <algorithm>

class PmergeMe {
public:
	std::vector<int> fordJohnsonSort(std::vector<int> &v);
	std::deque<int>	fordJohnsonSort(std::deque<int> &d);
};

#endif /* PMERGEME_HPP */
