/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:25:32 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/14 21:35:57 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors
AMateria::AMateria() : type("default")
{
	std::cout << "\e[0;33mDefault Constructor called of AMateria\e[0m" << std::endl;
}

AMateria::AMateria(const AMateria &copy) : type(copy.getType())
{
	std::cout << "\e[0;33mCopy Constructor called of AMateria\e[0m" << std::endl;
	// type =  copy.getType();
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "\e[0;33mCopy Constructor called of AMateria\e[0m" << std::endl;
	// this->type = type;
}

// Destructor
AMateria::~AMateria()
{
	std::cout << "\e[0;31mDestructor called of AMateria\e[0m" << std::endl;
}

// Operators
AMateria & AMateria::operator=(const AMateria &assign)
{
	// type = assign.getType();
	(void)assign;
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
