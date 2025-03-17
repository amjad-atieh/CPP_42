/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:41:12 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/17 19:50:44 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
Ice::Ice()
{
	type = "ice";
}

Ice::Ice(const Ice &copy)
{
	type = copy.getType();
}


// Destructor
Ice::~Ice()
{
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
