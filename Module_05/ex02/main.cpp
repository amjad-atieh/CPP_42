/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:03:18 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/14 22:01:15 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
    // Test 1
    {
        try
        {
            Bureaucrat bob("Bob", 1); // Very high grade
            ShrubberyCreationForm shrub("home");

            bob.signForm(shrub);    // should succeed
            bob.executeForm(shrub); // should create "home_shrubbery" file
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        }
    // Test 2
    {
        try
        {
            Bureaucrat alice("Alice", 1);
            RobotomyRequestForm robot("Marvin");

            alice.executeForm(robot); // should throw because not signed
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
    // Test 3
    {
        try
        {
            Bureaucrat lowGuy("LowGuy", 150);
            PresidentialPardonForm pardon("Ford");

            lowGuy.signForm(pardon); // should throw exception
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
    // Test 4
    {
        try
        {
            Bureaucrat signer("Signer", 25);
            Bureaucrat executor("Executor", 6); // too low for exec (needs 5)
            PresidentialPardonForm pardon("Trillian");

            signer.signForm(pardon); // should succeed
            executor.executeForm(pardon); // should throw exception
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
    // Test 5
    {
        try
        {
            Bureaucrat bot("Bot", 1);
            RobotomyRequestForm robot("Bender");

            bot.signForm(robot);
            for (int i = 0; i < 5; ++i)
                bot.executeForm(robot); // 50% chance of success
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
	return 0;
}
