/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:16:31 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/08 09:53:01 by aatieh           ###   ########.fr       */
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
	if (this == &assign)
		return *this;
	Animal::operator=(assign);
	Brain::operator=(assign);
	return *this;
}

//getters / setters
Brain	*Dog::getBrain() const
{
	return Brain;
}

void	Dog::setBrain(Brain assgin)
{
	brain = assgin;
}
