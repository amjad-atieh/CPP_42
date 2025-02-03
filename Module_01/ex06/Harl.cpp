/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:28:02 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/03 19:56:45 by aatieh           ###   ########.fr       */
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
	std::cout << "[DEBUG] " << "I like to weigh my fries to ensure I get"
		<< " the perfect portion every time. Precision matters!\n";
}

void	Harl::info( void )
{
	std::cout << "[INFO] " << "I can't believe they gave me fewer fries this time."
		<< " I paid for a full portion, and now I feel cheated!\n";
}

void	Harl::warning( void )
{
	std::cerr << "[WARNING] " << "I’ve been ordering fries from here for years."
		<< " You can’t just skimp on the portions because"
		<< " you’re in a rush.\n";
}

void	Harl::error( void )
{
	std::cerr << "[ERROR] " << "This is unacceptable! My fries are cold and soggy."
		<< " I demand a fresh batch immediately!"
		<< " or I will be escalating this to cooperate.\n";
}

void Harl::complain(std::string level)
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (functions[i].level == level)
			break;
	}
	switch (i)
	{
	case 4:
		std::cout << "Mumbling with dissatisfied munching noises\n";
		break;
	case 0:
		this->debug();
	case 1:
		this->info();
	case 2:
		this->warning();
	case 3:
		this->error();
		break;
	}
}
