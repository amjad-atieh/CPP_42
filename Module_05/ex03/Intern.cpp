/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:12:49 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/15 16:50:44 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


static AForm* createShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* createRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* createPresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

static void assigneFroms(FormEntry* forms)
{
	forms[0].name = "shrubbery creation";
	forms[0].creator = &createShrubberyForm;

	forms[1].name = "robotomy request";
	forms[1].creator = &createRobotomyForm;

	forms[2].name = "presidential pardon";
	forms[2].creator = &createPresidentialForm;
}

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
	assigneFroms(_forms);
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
	assigneFroms(_forms);
}

// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}

// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

// Memeber functions
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	for (size_t i = 0; i < FromsNum; ++i)
	{
		if (_forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return _forms[i].creator(target);
		}
	}
	std::cerr << "Intern couldn't find the form: " << formName << std::endl;
	return NULL;
}
