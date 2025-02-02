/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:49:38 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/02 19:51:15 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

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
	int	dst_index;

	for(int i = 0; i < 8; i++)
	{
		if (contacts[i].ContactEmpty())
			break;
		std::cout << "         " << i << "|";
		contacts[i].PrintContactColumn();
	}
	std::cout << "Enter the desired index: ";
	std::cin >> dst_index;
	if (std::cin.bad() || std::cin.eof() || std::cin.fail())
	{
		if (!std::cin.eof())
		{
			std::cin.clear();
			std::cout << "invalid index input\n";
		}
		return;
	}
	if (dst_index > 7)
		std::cout << "The number entered is out if range\n";
	else if (contacts[dst_index].ContactEmpty())
		std::cout << "Index entered is empty\n";
	else
		contacts[dst_index].PrintContact();
}
