/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:09:08 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/02 19:46:56 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"


Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_num = "";
	darkest_secret = "";
}

bool Contact::AddContact()
{
	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, first_name))
		return false;
	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, last_name))
		return false;
	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, nickname))
		return false;
	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, phone_num))
		return false;
	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, darkest_secret))
		return false;
	if (!first_name.length() || !last_name.length() || !nickname.length()
		|| !phone_num.length() || !darkest_secret.length())
	{
		std::cout << "Error: Empty field, contact wasn't saved\n";
		first_name = "";
		last_name = "";
		nickname = "";
		phone_num = "";
		darkest_secret = "";
		return false;
	}
	return true;
}

void	PrintColumn(std::string str, int last)
{
	std::string Spaces;

	Spaces = "          ";
	if (str.length() <= 10)
		std::cout << Spaces.substr(0, 10 - str.length()) << str;
	else
		std::cout << str.substr(0, 9) << ".";
	if (!last)
		std::cout << "|";
}

void Contact::PrintContactColumn()
{
	PrintColumn(first_name, 0);
	PrintColumn(last_name, 0);
	PrintColumn(nickname, 1);
	std::cout << '\n';
}

bool	Contact::ContactEmpty()
{
	if (phone_num == "")
		return (true);
	return(false);
}

void	Contact::PrintContact()
{
	std::cout << '\n';
	std::cout << "First Name: " << first_name << '\n';
	std::cout << "Last Name: " << last_name << '\n';
	std::cout << "Nickname: " << nickname << '\n';
	std::cout << "Phone Number: " << phone_num << '\n';
	std::cout << "Darkest Secret: " << darkest_secret << '\n';
	std::cout << '\n';
}
