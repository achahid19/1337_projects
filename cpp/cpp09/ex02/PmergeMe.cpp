#include "PmergeMe.hpp"

static inline void				insertSmallerElements(std::deque<int>& sorted, const std::list<int>& smaller);
static inline std::list<int>	sortPairsAndGetLarger(std::list<int>& lst);

// methods

std::deque<int> PmergeMe::fordJohnsonSort(std::list<int>& lst) {
    if (lst.size() <= 1) {
        return std::deque<int>(lst.begin(), lst.end()); // Base case: already sorted
    }

    // Step 1: Group elements into pairs and sort each pair
    std::list<int> largerElements = sortPairsAndGetLarger(lst);

    // Step 2: Recursively sort the larger elements
    std::deque<int> sortedLarger = fordJohnsonSort(largerElements);

    // Step 3: Insert the smaller elements into the sorted list
    std::list<int> smallerElements;
    std::list<int>::iterator it = lst.begin();

    while (it != lst.end()) {
        smallerElements.push_back(*it);
        it = std::next(it, 2); // Move to the next smaller element
		if (std::prev(it) == lst.end()) break ;
    }

    insertSmallerElements(sortedLarger, smallerElements);

    return sortedLarger;
}

// helper funcs

// Function to sort pairs and return the larger elements
static inline std::list<int> sortPairsAndGetLarger(std::list<int>& lst) {
    std::list<int>				largerElements;
    std::list<int>::iterator	it = lst.begin();
	std::list<int>::iterator	next;

    while (it != lst.end()) {
        next = std::next(it);
        if (next != lst.end()) {
            if (*it > *next) {
                largerElements.push_back(*it);
                std::swap(*it, *next); // Sort the pair
            } else {
                largerElements.push_back(*next);
            }
            it = std::next(next); // Move to the next pair
        } else {
            break; // Handle odd-sized list
        }
    }
    return largerElements;
}

// Function to insert smaller elements into the sorted list
static inline void insertSmallerElements(std::deque<int>& sorted, const std::list<int>& smaller) {
    for (std::list<int>::const_iterator num = smaller.begin(); num != smaller.end(); num++) {
        // Find the correct position using binary search
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), *num);
        sorted.insert(pos, *num);
    }
}
