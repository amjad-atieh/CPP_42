/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:49:38 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/03 18:49:26 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	index = 0;
}
void PhoneBook::AddPhoneBook()
{
	bool	contact_added;

	contact_added = contacts[index].AddContact();
	if (index < 7 && contact_added)
		index++;
	else if (contact_added)
		index = 0;
}

void PhoneBook::SearchPhoneBook()
{
	int			dst_index;
	std::string	input;

	std::cout << "     index|first name| last name|  nickname|\n";
	for(int i = 0; i < 8; i++)
	{
		if (contacts[i].ContactEmpty())
			break;
		std::cout << "         " << i << "|";
		contacts[i].PrintContactColumn();
	}
	std::cout << "Enter the desired index: ";
	std::getline(std::cin, input);
	dst_index = input[0] - '0';
	if (std::cin.bad() || std::cin.eof() || std::cin.fail() || input.length() != 1)
	{
		if (std::cin.eof())
			return;
		std::cerr << "invalid index input\n";
		return;
	}
	if (dst_index > 7)
		std::cerr << "The number entered is out if range\n";
	else if (contacts[dst_index].ContactEmpty())
		std::cerr << "Index entered is empty\n";
	else
		contacts[dst_index].PrintContact();
}
