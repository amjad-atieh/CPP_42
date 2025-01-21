/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:02 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/21 07:58:51 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	functions[0].level = "DEBUG";
	functions[0].function =  &Harl::debug;
	functions[1].level = "INFO";
	functions[1].function = &Harl::info;
	functions[2].level = "WARNING";
	functions[2].function = &Harl::warning;
	functions[3].level = "ERROR";
	functions[3].function = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "I like to weigh my fries to ensure I get"
		<< " the perfect portion every time. Precision matters!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I can't believe they gave me fewer fries this time."
		<< " I paid for a full portion, and now I feel cheated!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I’ve been ordering fries from here for years."
		<< " You can’t just skimp on the portions because"
		<< " you’re in a rush." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! My fries are cold and soggy."
		<< " I demand a fresh batch immediately!"
		<< " or I will be escalating this to cooperate." << std::endl;
}

void Harl::complain(std::string level) {
    switch (level.c_str()) {
        case "DEBUG":
            debug();
            // Fall through
        case "INFO":
            info();
            // Fall through
        case "WARNING":
            warning();
            // Fall through
        case "ERROR":
            error();
            break;
        default:
            std::cout << "Mumbling with dissatisfied munching noises" << std::endl;
    }
}
