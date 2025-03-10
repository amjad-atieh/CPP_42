/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:40:53 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/10 23:31:21 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	side_sign(Point const p1, Point const p2, Point const p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed p1, p2, p3;
	bool has_neg, has_pos;

	p1 = side_sign(point, a, b);
	p2 = side_sign(point, b, c);
	p3 = side_sign(point, c, a);
	
	has_neg = (p1 < 0 || p2 < 0 || p3 < 0);
	has_pos = (p1 > 0 || p2 > 0 || p3 > 0);
	return !(has_neg && has_pos);
}
