/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:18:30 by achahid-          #+#    #+#             */
/*   Updated: 2024/10/11 20:18:31 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {
private:
	Fixed const	_x;
	Fixed const	_y;

public:
	Point( void );
	Point( Point const& other );
	Point& operator=( Point const& other );
	~Point( void );

	bool bsp( Point const a, Point const b, Point const c, Point const point );
	
	/* Constructor by parameter */
	Point( float const n1, float const n2 );

	/* setters / getters */
	Fixed const&	getX( void ) const;
	Fixed const&	getY( void ) const;
};
