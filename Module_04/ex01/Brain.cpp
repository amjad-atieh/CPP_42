/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:56:57 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/08 09:46:15 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
	void *memory = operator new[] (IDEAS_NUM * sizeof(std::string), std::nothrow);
	ideas = static_cast<std::string *>(memory);	
	for (int i = 0; i < IDEAS_NUM; i++)
		new (&ideas[i]) std::string();
}

Brain::Brain(const Brain &copy)
{
	std::string *copy_ideas = copy.getIdeas();
	void *memory = operator new[] (IDEAS_NUM * sizeof(std::string), std::nothrow);
	ideas = static_cast<std::string *>(memory);
	for (int i = 0; i < IDEAS_NUM; i++)
		new (&ideas[i]) std::string(copy_ideas[i]);
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}


// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
	operator delete[] (ideas);
}


// Operators
Brain & Brain::operator=(const Brain &assign)
{
	// ideas = assign.getIdeas();
	std::string *copy_ideas = assign.getIdeas();
	for (int i = 0; i < IDEAS_NUM; i++)
		ideas[i] = copy_ideas[i];
	return *this;
}

void	Brain::setIdeas(const std::string *ideas)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas[i];
}

std::string	*Brain::getIdeas() const
{
	return ideas;
}
