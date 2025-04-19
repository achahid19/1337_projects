#include "PmergeMe.hpp"

template <typename T1, typename T2>
static void	makePairs(
	T1 &pairs,
	T2 &arr,
	size_t *odd_element_index	
);
template <typename T>
static void	insertOdd(T &main_chain, int value);
template <typename T>
static void	insertLosers(
	T &main_chain,
	T &losers
);

// simple implementation of the fordJohnsonSort
// step1: Pairing elements and detecting winners and losers
// step2: Recursively sorting the winners to form main_chain
// step3: Simply using lower_bound (binary search) to insert
// 		  each loser into the main_chain.
std::vector<int> PmergeMe::fordJohnsonSort(std::vector<int> &arr) {
	// Base cases
	if (arr.size() <= 1) {
		return arr;
	}
	
	size_t 								odd_element_index = -1;
	std::vector<std::pair<int, int>>	pairs;
	
	makePairs(pairs, arr, &odd_element_index);
	
	std::vector<int>	winners;
	for (size_t i = 0; i < pairs.size(); ++i) {
		winners.push_back(pairs[i].first);
	}

	std::vector<int>	sorted_winners = fordJohnsonSort(winners);
	std::vector<int>	main_chain = sorted_winners;
	
	if (odd_element_index != -1)
		insertOdd(main_chain, arr[odd_element_index]);
	
	std::vector<int>	losers;
	for (size_t i = 0; i < pairs.size(); i++) {
		losers.push_back(pairs[i].second);
	}
	insertLosers(main_chain, losers);

	return main_chain;
}

template <typename T1, typename T2>
static void	makePairs(
	T1 &pairs,
	T2 &arr,
	size_t *odd_element_index	
) {
	for (size_t i = 0; i < arr.size(); i += 2) {
		if (i + 1 < arr.size()) {
			int a = arr[i];
			int b = arr[i + 1];
			
			if (a > b) {
				pairs.push_back({a, b});
			} else {
				pairs.push_back({b, a});
			}
		} else {
			*odd_element_index = i;
		}
	}
}

template <typename T>
static void	insertOdd(T &main_chain, int value) {
	auto insert_pos = std::lower_bound(
		main_chain.begin(), main_chain.end(), value
	);
	main_chain.insert(insert_pos, value);
}

template <typename T>
static void	insertLosers(T &main_chain, T &losers) {
	for (size_t i = 0; i < losers.size(); ++i) {
		int loser = losers[i];
		
		// Find insertion point using binary search
		auto insert_pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), loser
		);
		main_chain.insert(insert_pos, loser);
	}
}

// for deque to avoid generic function
std::deque<int> PmergeMe::fordJohnsonSort(std::deque<int> &arr) {
	// Base cases
	if (arr.size() <= 1) {
		return arr;
	}
	
	size_t 								odd_element_index = -1;
	std::deque<std::pair<int, int>>		pairs;
	
	makePairs(pairs, arr, &odd_element_index);
	
	std::deque<int>	winners;
	for (size_t i = 0; i < pairs.size(); ++i) {
		winners.push_back(pairs[i].first);
	}

	std::deque<int>	sorted_winners = fordJohnsonSort(winners);
	std::deque<int>	main_chain = sorted_winners;
	
	if (odd_element_index != -1)
		insertOdd(main_chain, arr[odd_element_index]);
	
	std::deque<int>	losers;
	for (size_t i = 0; i < pairs.size(); i++) {
		losers.push_back(pairs[i].second);
	}
	insertLosers(main_chain, losers);

	return main_chain;
}
