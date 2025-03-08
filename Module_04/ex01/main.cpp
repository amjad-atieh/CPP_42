/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:16:14 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/08 09:43:10 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		const WrongAnimal* wrong = new WrongCat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << wrong->getType() << " " << std::endl;
		wrong->makeSound();
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
		delete wrong;
	}
	{
		int i;
		Animal *animals[6];
		for(i = 0; i < 6; i++)
		{
			if (i < 3)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		Dog j;
		// j = animals[i];
		for(i = 0; i < 6; i++)
			animals[i]->makeSound();
		for(i = 0; i < 6; i++)
			delete animals[i];
		j.makeSound();
		// delete j;
	}
	return 0;
}
