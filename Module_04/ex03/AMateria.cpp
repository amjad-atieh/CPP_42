/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:25:32 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/17 19:51:05 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors
AMateria::AMateria()
{
	type = "default";
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

// Destructor
AMateria::~AMateria()
{
}

// Operators
AMateria & AMateria::operator=(const AMateria &assign)
{
	type = assign.getType();
	return *this;
}

// Getters
std::string const &AMateria::getType() const
{
	return type;
}

// Member functions
void	AMateria::use(ICharacter& target)
{
	if (type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (type == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	else
		std::cout << "* punches " << target.getName() << "in the face *" << std::endl;
}
