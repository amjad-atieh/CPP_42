/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:39:43 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/05 06:11:56 by aatieh           ###   ########.fr       */
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
	value = init_value * (1 << f_bits);
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
	return (value / (1 << f_bits));
}
