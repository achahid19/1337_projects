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

static float triangleArea(Point const& a, Point const& b, Point const& c) {
    float area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2.0;
    return (area < 0) ? -area : area;
};

bool Point::bsp(Point const a, Point const b, Point const c, Point const point) {
    /* Calculate the area of triangle abc */
    float area = triangleArea(a, b, c);
    /* Calculate the area of triangle pbc */
    float area1 = triangleArea(point, b, c);
    /* Calculate the area of triangle apc */
    float area2 = triangleArea(a, point, c);
    /* Calculate the area of triangle abp */
    float area3 = triangleArea(a, b, point);
    if (!area1 || !area2 || !area3)
        return false;
    return (area == area1 + area2 + area3);
}
