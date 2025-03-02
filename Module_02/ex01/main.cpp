/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:40:00 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/02 21:27:31 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main()
{
	float value = -5.5;
	Fixed a(value);
	// Fixed b( a );
	// Fixed c;

	// std::cout << sizeof(int) << std::endl;
	// c = b;
	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;
	std::cout << "value is " << a.toFloat() << std::endl;
	
	return 0;
}
