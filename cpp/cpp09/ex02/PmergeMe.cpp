#include "PmergeMe.hpp"

static void	makePairs(
	std::vector<std::pair<int, int>> &pairs,
	std::vector<int> &arr,
	size_t *odd_element_index	
);
static void	insertOdd(std::vector<int> &main_chain, int value);
static void	insertLosers(
	std::vector<int> &main_chain,
	std::vector<int> &losers
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

static void	makePairs(
	std::vector<std::pair<int, int>> &pairs,
	std::vector<int> &arr,
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

static void	insertOdd(std::vector<int> &main_chain, int value) {
	auto insert_pos = std::lower_bound(
		main_chain.begin(), main_chain.end(), value
	);
	main_chain.insert(insert_pos, value);
}

static void	insertLosers(std::vector<int> &main_chain, std::vector<int> &losers) {
	for (size_t i = 0; i < losers.size(); ++i) {
		int loser = losers[i];
		
		// Find insertion point using binary search
		auto insert_pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), loser
		);
		main_chain.insert(insert_pos, loser);
	}
}

// for deque to avoid generic functions

static void	makePairs(
	std::deque<std::pair<int, int>> &pairs,
	std::deque<int> &arr,
	size_t			*odd_element_index
);
static void	insertOdd(std::deque<int> &main_chain, int value);
static void	insertLosers(std::deque<int> &main_chain, std::deque<int> &losers);


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

static void	makePairs(
	std::deque<std::pair<int, int>> &pairs,
	std::deque<int> &arr,
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

static void	insertOdd(std::deque<int> &main_chain, int value) {
	auto insert_pos = std::lower_bound(
		main_chain.begin(), main_chain.end(), value
	);
	main_chain.insert(insert_pos, value);
}

static void	insertLosers(std::deque<int> &main_chain, std::deque<int> &losers) {
	for (size_t i = 0; i < losers.size(); ++i) {
		int loser = losers[i];
		
		// Find insertion point using binary search
		auto insert_pos = std::lower_bound(
			main_chain.begin(), main_chain.end(), loser
		);
		main_chain.insert(insert_pos, loser);
	}
}
