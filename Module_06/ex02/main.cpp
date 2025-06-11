/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:57:40 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/11 14:41:26 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>

Base * generate(void)
{
	Base*	P;

	std::srand(std::time(NULL));
	if (rand() % 3 == 0)
		P = new A();
	else if (rand() % 2 == 0)
		P = new B();
	else
		P = new C();
	return P;
}

void identify(Base* p)
{
	if (p == NULL)
		std::cout << "Null pointer provided." << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Unknown class" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Class A" << std::endl;
		return;
	}
	catch(...)
	{
	}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "Class B" << std::endl;
		return;
	}
	catch(...)
	{
	}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "Class C" << std::endl;
		return;
	}
	catch(...)
	{
	}

	std::cout << "Unknown class" << std::endl;
}

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

	std::cout << "\nAll tests completed." << std::endl;
	return 0;
}
