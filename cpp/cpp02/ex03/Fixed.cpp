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
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->fixedPoint = other.getRawBits();
	}
	return (*this);
};

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
};

int	Fixed::getRawBits ( void ) const {
	return (fixedPoint);
};

void	Fixed::setRawBits( int const raw ) {
	fixedPoint = raw;
};

/* Public constructors */

Fixed::Fixed( int const number ) {
	std::cout << "Int constructor called" << std::endl;
	fixedPoint = number * (1 << fractionalBits); // number * 2^fractionalBits
};

Fixed::Fixed( float floatNumber ) {
	std::cout << "Float constructor called" << std::endl;
	fixedPoint = roundf(floatNumber * (1 << fractionalBits)); // floatNumber * 2^fractionalBits
};

/* Overload operator */

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
};

// Add public member functions to your class to overload the following operators:
//The 6 comparison operators: >, <, >=, <=, == and !=.
bool	Fixed::operator>( const Fixed& other ) const {
	return (fixedPoint > other.getRawBits());
};

bool	Fixed::operator<( const Fixed& other ) const {
	return (fixedPoint < other.getRawBits());
};

bool	Fixed::operator>=( const Fixed& other ) const {
	return (fixedPoint >= other.getRawBits());
};

bool	Fixed::operator<=( const Fixed& other ) const {
	return (fixedPoint <= other.getRawBits());
};

bool	Fixed::operator==( const Fixed& other ) const {
	return (fixedPoint == other.getRawBits());
};

bool	Fixed::operator!=( const Fixed& other ) const {
	return (fixedPoint != other.getRawBits());
};

int	Fixed::operator+( const Fixed& other ) const {
	return ((fixedPoint + other.getRawBits()) / (1 << fractionalBits));
};

int	Fixed::operator-( const Fixed& other ) const {
	return ((fixedPoint - other.getRawBits()) / (1 << fractionalBits));
};

float	Fixed::operator*( const Fixed& other ) const {
	return (((float)fixedPoint * (float)other.getRawBits()) / (1 << fractionalBits * 2));
};

float	Fixed::operator/( const Fixed& other ) const {
	return ((float)fixedPoint / (float)other.getRawBits());
};

float	Fixed::operator++( int ) {
	return ((float)fixedPoint++ / (1 << fractionalBits));
};

float	Fixed::operator--( int ) {
	return ((float)fixedPoint-- / (1 << fractionalBits));
};

float	Fixed::operator++( void ) {
	return ((float)++fixedPoint / (1 << fractionalBits));
};

float	Fixed::operator--( void ) {
	return ((float)--fixedPoint / (1 << fractionalBits));
};

// overload min, max
Fixed&	Fixed::min( Fixed& a, Fixed& b ) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
};

Fixed const&	Fixed::min( Fixed const& a, Fixed const& b ) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
};

Fixed&	Fixed::max( Fixed& a, Fixed& b ) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
};

Fixed const&	Fixed::max( Fixed const& a, Fixed const& b ) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
};

/* Public member functions */

int		Fixed::toInt( void ) const {
	return (fixedPoint / (1 << fractionalBits)); // fixedPoint / 2^fractionalBits
};

float	Fixed::toFloat( void ) const {
	return ((float)fixedPoint / (1 << fractionalBits)); // (float)fixedPoint / 2^fractionalBits
};
