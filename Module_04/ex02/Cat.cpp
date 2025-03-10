/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:16:26 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/11 01:54:36 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat() : Animal("Cat")
{
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
	brain = new Brain();
	*brain = *(copy.brain);
}

// Destructor
Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
	delete brain;
}

// Operators
Cat & Cat::operator=(const Cat &assign)
{
	std::cout << "\e[0;32mAssignation operator called of Cat\e[0m" << std::endl;
	if (this == &assign)
		return *this;
	Animal::operator=(assign);
	*brain = *(assign.brain);
	return *this;
}

//getters / setters
Brain	&Cat::getBrain() const
{
	return *brain;
}

void	Cat::setBrain(Brain assgin)
{
	brain = &assgin;
}
