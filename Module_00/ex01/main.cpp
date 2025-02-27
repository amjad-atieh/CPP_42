/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:09:52 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/18 19:58:33 by aatieh           ###   ########.fr       */
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
		if (command == "ADD")
			Phone_Book.AddPhoneBook();
		else if (command == "SEARCH")
			Phone_Book.SearchPhoneBook();
		else if (command == "EXIT")
			break ;
		if (std::cin.fail() || std::cin.eof() || std::cin.bad())
			break ;
	}
	return 0;
}
