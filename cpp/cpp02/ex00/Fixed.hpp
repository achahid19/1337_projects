/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:16:01 by achahid-          #+#    #+#             */
/*   Updated: 2024/10/09 09:16:02 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					fixedPoint;
	static int const	fractionalBits;
	
public:
	Fixed( void );
	Fixed( const Fixed& other );
	Fixed& operator=( const Fixed& other );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif /* FIXED_HPP */
