#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

/* function template */
template <typename T>
typename T::iterator easyfind( T& container, int n ) {
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end()) {
		throw	std::runtime_error("Value not found!");
	}
	return it;
};

#endif /* EASYFIND_HPP */
