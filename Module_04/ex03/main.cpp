/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:24:50 by aatieh            #+#    #+#             */
/*   Updated: 2025/04/21 18:51:43 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	AMateria* tmp;
	IMateriaSource* src = new MateriaSource();
	tmp = new Ice();
	src->learnMateria(tmp);
	delete tmp;
	tmp = new Cure();
	src->learnMateria(tmp);
	delete tmp;

	ICharacter* me = new Character("me");

	// Test creating and equipping Ice materia
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	// Test creating and equipping Cure materia
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	ICharacter* bob = new Character("bob");

	// Test using equipped materias
	std::cout << "Using the two equipped materias:" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	// Test unequipping and using an unequipped slot
	std::cout << "Unequipping and using an unequipped slot:" << std::endl;
	me->unequip(0);
	me->use(0, *bob);

	// Test equipping more materias than the limit
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	// Test using all equipped materias
	std::cout << "Using all equipped materias:" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	// Test unequipping all materias
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);

	// Test using after unequipping all materias
	std::cout << "Using after unequipping all materias:" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	// Test equipping different materias after unequipping all
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;

	// Test using all equipped materias
	std::cout << "Using all equipped materias:" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	// Clean up
	delete bob;
	delete me;
	delete src;

	return 0;
}
