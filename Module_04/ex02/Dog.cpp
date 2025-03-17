/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:16:31 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/17 22:05:15 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog() : Animal("Dog")
{
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
	brain = new Brain();
	*brain = *(copy.brain);
}

// Destructor
Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
	delete brain;
}

// Operators
Dog & Dog::operator=(const Dog &assign)
{
	std::cout << "\e[0;32mAssignation operator called of Dog\e[0m" << std::endl;
	if (this == &assign)
		return *this;
	Animal::operator=(assign);
	*brain = *(assign.brain);
	return *this;
}

//getters / setters
Brain	&Dog::getBrain() const
{
	return *brain;
}

void	Dog::setBrain(Brain assgin)
{
	brain = &assgin;
}
