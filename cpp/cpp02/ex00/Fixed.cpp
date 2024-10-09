/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:15:47 by achahid-          #+#    #+#             */
/*   Updated: 2024/10/09 09:15:48 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::fractionalBits = 8;

Fixed::Fixed( void ) {
	fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor operator called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other) {
		this->fixedPoint = other.getRawBits();
	}
	return (*this);
};

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
};

int	Fixed::getRawBits ( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
};

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	fixedPoint = raw;
};
