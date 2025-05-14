/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:03:18 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/14 16:46:05 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
 std::cout << "=== Test 1: Bureaucrat successfully signs Form ===" << std::endl;
    try {
        Bureaucrat john("John", 50);
        Form taxForm("TaxForm", 100, 150);
        std::cout << john << std::endl;
        std::cout << taxForm << std::endl;

        john.signForm(taxForm); // should succeed
        std::cout << taxForm << std::endl;
        
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Bureaucrat fails to sign Form due to low grade ===" << std::endl;
    try {
        Bureaucrat lowRank("Joe", 150);
        Form topSecret("TopSecretForm", 50, 20);
        std::cout << lowRank << std::endl;
        std::cout << topSecret << std::endl;

        lowRank.signForm(topSecret); // should throw GradeTooLowException
    } catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Create Form with invalid grade (too high) ===" << std::endl;
    try {
        Form invalidForm("ImpossibleForm", 0, 150); // Grade too high (0)
    } catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Create Form with invalid grade (too low) ===" << std::endl;
    try {
        Form invalidForm("TooEasyForm", 1, 160); // Grade too low (160)
    } catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
	return 0;
}
