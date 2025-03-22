/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:25:32 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/22 19:38:17 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors
AMateria::AMateria() : type("default")
{
}

AMateria::AMateria(const AMateria &copy) : type(copy.type)
{
	*this = copy;
}

AMateria::AMateria(std::string const &type) : type(type)
{
}

// Destructor
AMateria::~AMateria()
{
}

// Operators
AMateria & AMateria::operator=(const AMateria &assign)
{
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
	std::cout << "* punches " << target.getName() << "in the face *" << std::endl;
}
