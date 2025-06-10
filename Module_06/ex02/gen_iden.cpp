/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_iden.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:19:51 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/10 16:21:33 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen_iden.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>

Base * generate(void)
{
	Base*	P;
	int		value;

	std::srand(static_cast<unsigned int>(std::clock()));
	value = rand();
	if (value % 3 == 0)
		P = new A();
	else if (value % 3 == 1)
		P = new B();
	else
		P = new C();
	return P;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
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
	Base *d = &p;
	if (dynamic_cast<A*>(d))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(d))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(d))
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Unknown class" << std::endl;
}

