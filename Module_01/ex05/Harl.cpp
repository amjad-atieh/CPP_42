/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:02 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/03 20:58:15 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	functions[0].level = "DEBUG";
	functions[0].complain = &Harl::debug;
	functions[1].level = "INFO";
	functions[1].complain = &Harl::info;
	functions[2].level = "WARNING";
	functions[2].complain = &Harl::warning;
	functions[3].level = "ERROR";
	functions[3].complain = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "I like to weigh my fries to ensure I get"
		<< " the perfect portion every time. Precision matters!\n";
}

void	Harl::info( void )
{
	std::cout << "I can't believe they gave me fewer fries this time."
		<< " I paid for a full portion, and now I feel cheated!\n";
}

void	Harl::warning( void )
{
	std::cerr << "I’ve been ordering fries from here for years."
		<< " You can’t just skimp on the portions because"
		<< " you’re in a rush.\n";
}

void	Harl::error( void )
{
	std::cerr << "This is unacceptable! My fries are cold and soggy."
		<< " I demand a fresh batch immediately!"
		<< " or I will be escalating this to cooperate.\n";
}

void	Harl::complain( std::string level )
{

	for(int i = 0; i < NUMOFLEVELS; i++)
	{
		if (functions[i].level == level)
		{
			(this->*functions[i].complain)();
			return ;
		}
	}
	std::cout << "Mumbling with dissatisfied munching noises\n";
}
