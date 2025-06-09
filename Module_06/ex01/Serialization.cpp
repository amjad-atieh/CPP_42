/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:57:42 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/09 17:57:43 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

// Constructors
Serialization::Serialization()
{
	std::cout << "\e[0;33mDefault Constructor called of Serialization\e[0m" << std::endl;
}

Serialization::Serialization(const Serialization &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Serialization\e[0m" << std::endl;
}


// Destructor
Serialization::~Serialization()
{
	std::cout << "\e[0;31mDestructor called of Serialization\e[0m" << std::endl;
}


// Operators
Serialization & Serialization::operator=(const Serialization &assign)
{
	(void) assign;
	return *this;
}

// Member funtions
uintptr_t Serialization::serialize(Data* ptr)
{
	uintptr_t	raw = reinterpret_cast <uintptr_t>(ptr);
	return (raw);
}

Data* Serialization::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast <Data *>(raw);
	return ptr;
}

