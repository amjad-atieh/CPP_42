/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:41:00 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/22 19:39:28 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors
Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	*this = copy;
}


// Destructor
Cure::~Cure()
{
}


// Operators
Cure & Cure::operator=(const Cure &assign)
{
	AMateria::operator=(assign);
	return *this;
}

// Member functions
AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
