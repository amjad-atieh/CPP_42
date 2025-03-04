/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:02:45 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/04 18:00:37 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{
}

Point::Point(const float &x_init, const float &y_init) : x(x_init), y(y_init)
{
}



Point::~Point()
{
}


Point &Point::operator=(const Point &assign)
{
	(void)assign;
	return *this;
}

Fixed const	Point::getX( void ) const
{
	return x;
}

Fixed const	Point::getY( void ) const
{
	return y;
}
