/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:39:43 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/02 21:53:28 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed( const Fixed &src )
{
	std::cout << "Copy constructor called\n";
	value = src.getRawBits();
}

int	toPow(int num, int pow)
{
	int	res;
	int	i;

	if (pow == 0)
		return (1);
	i = pow - 1;
	res = num;
	while (i-- > 0)
		res *= num;
	return res;
}

Fixed::Fixed( const int init_value )
{
	std::cout << "Int constructor called\n";
	value = init_value * toPow(2, f_bits);
}

Fixed::Fixed( const float init_value )
{
	std::cout << "Float constructor called\n";
	value = roundf(init_value * toPow(2, f_bits));
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		value = rhs.getRawBits();
	return *this;
}

float	&Fixed::operator<<(const Fixed &rhs)
{
	float	f_value;

	f_value = rhs.toFloat();
	// std::cout << "Copy assignment operator called\n";
	return (f_value);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return value;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	value = raw;
}

float	Fixed::toFloat( void ) const
{
	float	f_value;

	std::cout << "toFloat member function called\n";
	f_value = (float)value / (float)toPow(2, f_bits);
	return f_value;
}

int	Fixed::toInt( void ) const
{
	int	i_value;

	std::cout << "toInt member function called\n";
	i_value = value / toPow(2, f_bits);
	return i_value;
}
