/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:13:00 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/15 16:13:01 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), 72, 45), _target(copy.getTarget())
{
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\e[0;33mVariable Constructor called of PresidentialPardonForm\e[0m" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}

// Getters
std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

// Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	(void)assign;
	return *this;
}

// member functions
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->excutableCheck(executor);
	if (std::rand() % 2 == 0)
		std::cout << _target << "has been robotomized" << std::endl;
	else
		std::cout << _target << "'s robotomy failed." << std::endl;
}
