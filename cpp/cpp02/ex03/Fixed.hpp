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
#include <cmath>

class Fixed {
private:
	int					fixedPoint;
	static int const	fractionalBits;
	
public:
	Fixed( void );
	Fixed( const Fixed& other );
	Fixed& operator=( const Fixed& other );
	~Fixed( void );

	/* Public member functions */
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;

	/* Public constructors */
	Fixed( int const number );
	Fixed( float const floatNumber );

	/* Overload operator */
	friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

	// compare operators
	bool	operator>( const Fixed& other ) const;
	bool	operator<( const Fixed& other ) const;
	bool	operator>=( const Fixed& other ) const;
	bool	operator<=( const Fixed& other ) const;
	bool	operator==( const Fixed& other ) const;
	bool	operator!=( const Fixed& other ) const;

	// arithmetic operators
	int		operator+( const Fixed& other ) const;
	int		operator-( const Fixed& other ) const;
	float	operator*( const Fixed& other ) const;
	float	operator/( const Fixed& other ) const;
	float	operator++( int );
	float	operator--( int );
	// pre-increment and pre-decrement
	float	operator++( void );
	float	operator--( void );

	// overload min, max
	static Fixed&			min( Fixed& a, Fixed& b );
	static Fixed const& 	min( Fixed const& a, Fixed const& b );
	static Fixed&			max( Fixed& a, Fixed& b );
	static Fixed const&		max( Fixed const& a, Fixed const& b );
};

#endif /* FIXED_HPP */
