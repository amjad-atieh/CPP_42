/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:39:43 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/12 18:37:48 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructors
Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	value = 0;
}

Fixed::Fixed( const Fixed &src )
{
	std::cout << "Copy constructor called\n";
	value = src.getRawBits();
}

Fixed::Fixed( const int init_value )
{
	std::cout << "Int constructor called\n";
	value = init_value << f_bits;
}

Fixed::Fixed( const float init_value )
{
	std::cout << "Float constructor called\n";
	value = roundf(init_value * (1 << f_bits));
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

// Operators
Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		value = rhs.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// Member functions
int	Fixed::getRawBits( void ) const
{
	return value;
}

void	Fixed::setRawBits( int const raw )
{
	value = raw;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(value) / (1 << f_bits);
}

int	Fixed::toInt( void ) const
{
	return (value >> f_bits);
}

bool	Fixed::operator>( const Fixed &src ) const
{
	return (value > src.getRawBits());
}

bool	Fixed::operator<( const Fixed &src ) const
{
	return (value < src.getRawBits());
}

bool	Fixed::operator>=( const Fixed &src ) const
{
	return (value >= src.getRawBits());
}

bool	Fixed::operator<=( const Fixed &src ) const
{
	return (value <= src.getRawBits());
}

bool	Fixed::operator==( const Fixed &src ) const
{
	return (value == src.getRawBits());
}

bool	Fixed::operator!=( const Fixed &src ) const
{
	return (value != src.getRawBits());
}

Fixed	Fixed::operator+( const Fixed &src ) const
{
	Fixed result;
	result.setRawBits(value + src.getRawBits());
	return result;
}

Fixed	Fixed::operator-( const Fixed &src ) const
{
	Fixed result;
	result.setRawBits(value - src.getRawBits());
	return result;
}

Fixed	Fixed::operator*( const Fixed &src ) const
{
	long long result = static_cast<long long>(value) * src.getRawBits();
	Fixed tmp;
	tmp.setRawBits(result >> f_bits);
	return tmp;
}

Fixed	Fixed::operator/( const Fixed &src ) const
{
	Fixed result;
	result.setRawBits((value << f_bits) / src.getRawBits());
	return result;
}

Fixed	&Fixed::operator++( void )
{
	++value;
	return *this;
}

Fixed	&Fixed::operator--( void )
{
	--value;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed tmp = *this;
	value++;
	return tmp;
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp = *this;
	value++;
	return tmp;
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b )
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b )
{
	return (a > b ? a : b);
}

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	return (a > b ? a : b);
}
