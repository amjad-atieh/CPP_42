/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:49:38 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/19 07:18:02 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include <limits>

class PhoneBook
{
	int		index;
	Contact contacts[8];

public:
	PhoneBook();
	void AddPhoneBook();
	void SearchPhoneBook();
};

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
			break ;
		std::cout << "         " << i << "|";
		contacts[i].PrintContact();
		std::cout << std::endl;
	}
	std::cout << "Enter the desired index\n";
	std::cin >> dst_index;
	if (dst_index > 7)
		std::cout << "The number entered is out if range\n";
	else if (contacts[dst_index].ContactEmpty())
		std::cout << "Index entered is empty\n";
	else
		contacts[dst_index].PrintContact();
}

int	main()
{
	PhoneBook	Phone_Book;
	std::string	command;

	while (1)
	{
		std::cout << "Enter command:\n";
		std::cin >> command;
		if (command == "ADD")
			Phone_Book.AddPhoneBook();
		else if (command == "SEARCH")
			Phone_Book.SearchPhoneBook();
		else if (command == "EXIT")
			break ;
		if (std::cin.fail())
			break ;
	}
	return 0;
}
