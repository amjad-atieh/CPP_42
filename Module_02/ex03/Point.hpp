/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:04:32 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/04 17:54:28 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"


class Point
{
	public:

		Point();
		Point(const Point &copy);
		Point(const float &x_init, const float &y_init);
		~Point();
		
		Point &operator=(const Point &assign);
		
		Fixed const	getX( void ) const;
		Fixed const	getY( void ) const;
		
	private:

		Fixed const	x;
		Fixed const	y;
};

#endif