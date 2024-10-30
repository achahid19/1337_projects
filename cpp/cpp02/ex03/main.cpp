/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:15:39 by achahid-          #+#    #+#             */
/*   Updated: 2024/10/09 09:15:40 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main( void ) {
	Point	z;
	Point	a(1, 1);
	Point   b(20, 1);
	Point   c(10, 30);
	Point	point(15, 20);
	bool	result;

	result = z.bsp(a, b, c, point);
	result == false ? std::cout << "false" : std::cout << "true";
	std::cout << std::endl;
	return 0;
};
