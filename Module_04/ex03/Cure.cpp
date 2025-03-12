/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:41:00 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/12 06:57:29 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors
Cure::Cure()
{
	std::cout << "\e[0;33mDefault Constructor called of Cure\e[0m" << std::endl;
	type = "cure";
}

Cure::Cure(const Cure &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Cure\e[0m" << std::endl;
	type = copy.getType();
}


// Destructor
Cure::~Cure()
{
	std::cout << "\e[0;31mDestructor called of Cure\e[0m" << std::endl;
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

	clone = new Cure(this);
	return (clone);
}
