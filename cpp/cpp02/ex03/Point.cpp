/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:24:17 by achahid-          #+#    #+#             */
/*   Updated: 2024/10/11 20:24:18 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Canonical form */

Point::Point( void ) : _x(0), _y(0) {
	// std::cout << "[Point] Default constructor called" << std::endl;
};

Point::Point( Point const& other ): _x(other._x), _y(other._y) {
	// std::cout << "[Point] Copy constructor called" << std::endl;
	//*this=(other);
};

Point& Point::operator=( Point const &other ) {
	// std::cout << "[Point] copy assignement overload called" << std::endl;
	(void)other;
	return (*this);
};

Point::~Point( void ) {
	// std::cout << "[Point] Destuctor called" << std::endl;
    return ;
};

/* Contructor by parameter */

Point::Point( float const n1, float const n2 ) : _x(n1), _y(n2) {
	// std::cout << "[Point] Constructor by paramter called" << std::endl;
}

/* getters */

Fixed const& Point::getX( void ) const {
    return (_x);
};

Fixed const& Point::getY( void ) const {
    return (_y);
};

/* bsp method */
