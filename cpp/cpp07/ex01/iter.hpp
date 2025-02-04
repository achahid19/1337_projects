#ifndef	ITER_HPP
#define	ITER_HPP

#include <iostream>

template <typename T>
void	iter( T *arr, size_t arr_size, void	(*func)( T element ) ) {
	for (size_t i = 0; i < arr_size; i++) func(arr[i]);
}

template <typename T>
void	func( T element ) {
	std::cout << "element is: " << element << std::endl;
}

#endif /* ITER_HPP */
