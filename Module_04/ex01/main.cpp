/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:16:14 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/20 17:11:59 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	int		i;
	Animal	*animals[6];
	for(i = 0; i < 6; i++)
	{
		if (i < 3)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for(i = 0; i < 6; i++)
		animals[i]->makeSound();
	Cat *cat = new Cat();
	cat->setIdea(0, "I am a cat");
	cat->setIdea(1, "that loves to");
	cat->setIdea(2, "sleep all day");
	cat->setIdea(3, "and play all night");
	Cat copy(*cat);
	for(i = 0; i < 6; i++)
		delete animals[i];
	delete cat;
	for (i = 0; i < 4; i++)
		std::cout << copy.getIdea(i) << std::endl;
	return 0;
}
