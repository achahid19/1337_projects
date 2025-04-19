#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <deque>
#include <vector>
#include <cstdlib>

class PmergeMe {
public:
 	PmergeMe( void );
	PmergeMe( PmergeMe& copy );
	PmergeMe&	operator=( PmergeMe& copy );
	~PmergeMe( void );

	// sorting methods
	std::vector<int>	fordJohnsonSort(std::vector<int> &v);
	std::deque<int>		fordJohnsonSort(std::deque<int> &d);
};

#endif /* PMERGEME_HPP */
