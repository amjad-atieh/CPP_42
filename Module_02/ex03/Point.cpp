/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:02:45 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/07 12:22:09 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors
Point::Point() : x(0), y(0)
{
}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{
}

Point::Point(const float &x_init, const float &y_init) : x(x_init), y(y_init)
{
}

// Destructor
Point::~Point()
{
}

// Operators
Point &Point::operator=(const Point &assign)
{
	(void)assign;
	std::cout << "Point assignation operator does nothing" << std::endl;
	return *this;
}

// Member functions
Fixed const	Point::getX( void ) const
{
	return x;
}

Fixed const	Point::getY( void ) const
{
	return y;
}
