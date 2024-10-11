/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:18:13 by achahid-          #+#    #+#             */
/*   Updated: 2024/10/11 21:18:16 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float   triangleArea( Point const& a, Point const& b, Point const& c) {
    return (std::abs((a.getX()*(b.getY()-c.getY()) + b.getX()*(c.getY()-a.getY()) + c.getX()*(a.getY()-b.getY()))) / 2.0);
};

bool	Point::bsp( Point const a, Point const b, Point const c, Point const point ) {
	// Need to calculate the area of the triangle
	// creates a functions that calculates the area of a triangle
	float area1 = triangleArea(a, b, c);
    float area2 = triangleArea(point, b, c);
    float area3 = triangleArea(a, point, c);
    float area4 = triangleArea(a, b, point);

    std::cout << area1 << std::endl;
    std::cout << area2 << std::endl;
    std::cout << area3 << std::endl;
    std::cout << area4 << std::endl;

    return (area1 == area2 + area3 + area4);
}
