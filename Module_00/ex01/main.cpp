/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:09:52 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/27 20:33:26 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook	Phone_Book;
	std::string	command;

	while (1)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (std::cin.fail() || std::cin.eof() || std::cin.bad())
			break ;
		if (command == "ADD")
			Phone_Book.AddPhoneBook();
		else if (command == "SEARCH")
			Phone_Book.SearchPhoneBook();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command, accepted commands are ADD, SEARCH, and EXIT\n";
	}
	return 0;
}
