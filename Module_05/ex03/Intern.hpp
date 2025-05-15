/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:12:51 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/15 16:59:55 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# define FromsNum 3

typedef AForm* (*FormCreator)(const std::string &target);

struct FormEntry {
	std::string name;
	FormCreator creator;
};

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);

		// Destructor
		~Intern();

		// Operators
		Intern & operator=(const Intern &assign);

		// Member functions
		AForm *makeForm(const std::string &formName, const std::string &target) const;

	private:
		FormEntry _forms[FromsNum];
};

#endif