/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:40:00 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/04 18:06:23 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "bsp.cpp"
#include <iostream>

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(0.0f, 4.0f);
	Point point(2.0f, 2.0f);

	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle\n";
	else
		std::cout << "The point is outside the triangle\n";
	return 0;
}
