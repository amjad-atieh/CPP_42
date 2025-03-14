/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:41:12 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/14 17:36:23 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
Ice::Ice()
{
	std::cout << "\e[0;33mDefault Constructor called of Ice\e[0m" << std::endl;
	type = "ice";
}

Ice::Ice(const Ice &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Ice\e[0m" << std::endl;
	type = copy.getType();
}


// Destructor
Ice::~Ice()
{
	std::cout << "\e[0;31mDestructor called of Ice\e[0m" << std::endl;
}


// Operators
Ice & Ice::operator=(const Ice &assign)
{
	type = assign.getType();
	return *this;
}

// Member functions
AMateria* Ice::clone() const
{
	AMateria *clone = NULL;

	try {
		clone = new Ice(*this);
	} catch (std::bad_alloc &e) {
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		return (NULL);
	}
	return (clone);
}
