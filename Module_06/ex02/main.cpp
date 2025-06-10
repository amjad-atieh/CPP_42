/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:57:40 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/10 16:21:58 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen_iden.hpp"
#include <iostream>

int main()
{
	std::cout << "---- Test 1: Single generate call ----" << std::endl;
	// Base *p = generate();
	std::cout << "Generating instances of A, B, and C:" << std::endl;
	Base *p = new A();
	std::cout << "identify(p): ";
	identify(p);
	std::cout << "identify(*p): ";
	identify(*p);
	delete p;

	p = new B();
	std::cout << "identify(p): ";
	identify(p);
	std::cout << "identify(*p): ";
	identify(*p);
	delete p;

	p = new C();
	std::cout << "identify(p): ";
	identify(p);
	std::cout << "identify(*p): ";
	identify(*p);
	delete p;

	std::cout << "\n---- Test 2: Multiple generate calls ----" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		Base *p2 = generate();
		std::cout << "Test " << i + 1 << " - identify(p2): ";
		identify(p2);
		std::cout << "Test " << i + 1 << " - identify(*p2): ";
		identify(*p2);
		delete p2;
	}

	return 0;
}
