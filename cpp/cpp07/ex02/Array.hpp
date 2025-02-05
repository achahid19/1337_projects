#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array { // Class template
private:
	T			*data;
	unsigned int _size;
	
public:
	/* Canonical form */
	Array( void );
	Array( unsigned int n );
	Array( const Array& copy );
	const Array& operator=( const Array& copy );
	~Array( void );

	/* Methods */
	unsigned int	size( void ) const;

	/* operator overload */
	T&	operator[]( int index ) const;
};

/* Canonical form */
template <typename T> 
Array<T>::Array( void ) : data(NULL), _size(0) {
	std::cout << "[ Array ]: Default constructor!" << std::endl;
}

template <typename T>
Array<T>::Array( unsigned int n ) : _size(n) {
	std::cout << "[ Array ]: Constructor by parameter called!" << std::endl;
	data = new T[n];
}

template <typename T>
Array<T>::Array( const Array& copy ) {
	std::cout << "[ Array ]: Copy constructor called!" << std::endl;
	(*this)=copy;
}

template <typename T>
const Array<T>&	Array<T>::operator=( const Array& copy ) {
	std::cout << "[ Array ]: Copy assignment called!" << std::endl;
	if (this != &copy) {
		this->_size = copy.size();
		this->data = new T[this->_size];
		for (size_t i = 0; i < _size; i++) {
			data[i] = copy[i];
		}
	}
	return *this;
};

template <typename T>
Array<T>::~Array( void ) {
	std::cout << "[ Array ]: Destructor called!" << std::endl;
	delete[] data;
}

/* Methods */

template <typename T>
unsigned int Array<T>::size( void ) const {
	return _size;
}

/* Operator Overload */

template <typename T>
T&	Array<T>::operator[]( int index ) const {
	if (index < 0 || index >= int(_size))
		throw std::out_of_range("Index out of range");
	return data[index];
};

#endif /* ARRAY_HPP */
