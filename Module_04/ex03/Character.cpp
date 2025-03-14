/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:50:47 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/14 21:29:38 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors
Character::Character() : name("default")
{
	std::cout << "\e[0;33mDefault Constructor called of Character\e[0m" << std::endl;
	materias_count = 0;
	for (int i = 0; i < MAX_MATERIAS; i++)
		materias[i] = NULL;
}

Character::Character(const Character &copy) : name(copy.getName())
{
	std::cout << "\e[0;33mCopy Constructor called of Character\e[0m" << std::endl;
	*this = copy;
}


// Destructor
Character::~Character()
{
	std::cout << "\e[0;31mDestructor called of Character\e[0m" << std::endl;
	for (int i = 0; i < materias_count; i++)
		delete materias[i];
}


// Operators
Character & Character::operator=(const Character &assign)
{
	// for (int i = 0; i < materias_count; i++)
	// 	delete materias[i];
	// materias_count = assign.getMateriasCount();
	// for (int i = 0; i < materias_count; i++)
	// 	materias[i] = assign.getMateria(i)->clone();
	return *this;
}

//getters / setters
std::string const	&Character::getName() const
{
	return name;
}

// AMateria*	Character::getMateria(int idx) const
// {
// 	if (idx < 0 || idx >= materias_count)
// 		return NULL;
// 	return materias[idx];
// }

// int	Character::getMateriasCount() const
// {
// 	return materias_count;
// }

//Member functions
void Character::equip(AMateria* m)
{
	int i = 0;

	while (i < materias_count && materias[i])
		i++;
	if (i < MAX_MATERIAS)
		materias[materias_count++] = m->clone();
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_MATERIAS || !materias[idx])
		return;
	materias[idx] = NULL;
}
