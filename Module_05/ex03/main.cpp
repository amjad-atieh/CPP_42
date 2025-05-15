/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:03:18 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/15 17:01:19 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main()
{
	try {
		Intern someRandomIntern;
		Bureaucrat boss("Alice", 1);
		Bureaucrat lowRank("Bob", 150);

		// Test 1: Valid form creation
		AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
		AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Ford");

		// Test 2: Invalid form creation
		AForm* unknown = someRandomIntern.makeForm("dance form", "Nobody");

		// Test 3: Sign and execute (success)
		boss.signForm(*shrub);
		boss.executeForm(*shrub);

		boss.signForm(*robot);
		boss.executeForm(*robot);

		boss.signForm(*pardon);
		boss.executeForm(*pardon);

		// Test 4: Execute without signing
		AForm* testForm = someRandomIntern.makeForm("shrubbery creation", "desk");
		try {
			boss.executeForm(*testForm);
		} catch (const std::exception &e) {
			std::cerr << "Execution without signing: " << e.what() << std::endl;
		}

		// Test 5: Low grade signing
		try {
			lowRank.signForm(*testForm);
		} catch (const std::exception &e) {
			std::cerr << "Low grade signing: " << e.what() << std::endl;
		}

		// Test 6: Low grade execution
		boss.signForm(*testForm);
		try {
			lowRank.executeForm(*testForm);
		} catch (const std::exception &e) {
			std::cerr << "Low grade execution: " << e.what() << std::endl;
		}

		// Clean up
		delete shrub;
		delete robot;
		delete pardon;
		delete unknown;
		delete testForm;

	} catch (const std::exception &e) {
		std::cerr << "Caught fatal error: " << e.what() << std::endl;
	}
	return 0;
}
