#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

/* function template */
template <typename T>
typename T::iterator easyfind( T& container, int n ) {
	typename T::iterator	it;
	// if we define the type that way T<int>::iterator
	// the compiler is not sure that T<int> has a nested
	// type called iterator
	// by typename we tell the compiler that T::iterator
	// is a type

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end()) {
		throw	std::runtime_error("Value not found!");
	}
	return it;
};

#endif /* EASYFIND_HPP */
