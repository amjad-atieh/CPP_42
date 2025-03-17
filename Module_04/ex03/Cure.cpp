/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:41:00 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/17 19:50:50 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors
Cure::Cure()
{
	type = "cure";
}

Cure::Cure(const Cure &copy)
{
	type = copy.getType();
}


// Destructor
Cure::~Cure()
{
}


// Operators
Cure & Cure::operator=(const Cure &assign)
{
	type = assign.getType();
	return *this;
}

// Member functions
AMateria* Cure::clone() const
{
	AMateria *clone = NULL;

	try {
		clone = new Cure(*this);
	} catch (std::bad_alloc &e) {
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		return (NULL);
	}
	return (clone);
}
