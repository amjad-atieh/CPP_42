/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:56:57 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/11 02:01:41 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	this->setIdeas(copy.getIdeas());
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}


// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}


// Operators
Brain & Brain::operator=(const Brain &assign)
{
	for (int i = 0; i < IDEAS_NUM; i++)
		setIdea(i, assign.getIdea(i));
	return *this;
}

void	Brain::setIdeas(const std::string *ideas)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas[i];
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= IDEAS_NUM)
		return;
	ideas[index] = idea;
}

const std::string	*Brain::getIdeas() const
{
	return ideas;
}

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index >= IDEAS_NUM)
		throw std::out_of_range("Index out of range");
	return (ideas[index]);
}
