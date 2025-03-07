/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:40:00 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/07 17:46:09 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c;

	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	if (a > b)
		std::cout << a << " is greater than " << b << std::endl;
	else if (a == b)
		std::cout << a << " is equal to " << b << std::endl;
	else if (a < b)
		std::cout << a << " is less than " << b << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	c = Fixed(4) * Fixed(2);
	std::cout << c << std::endl;
	c = Fixed(4) / Fixed(2);
	std::cout << c << std::endl;
	return 0;
}
