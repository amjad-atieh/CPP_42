/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:09:08 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/19 06:53:47 by aatieh           ###   ########.fr       */
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
	std::cout << "Enter first name\n";
	std::cin >> first_name;
	std::cout << "Enter last name\n";
	std::cin >> last_name;
	std::cout << "Enter nickname\n";
	std::cin >> nickname;
	std::cout << "Enter phone number\n";
	std::cin >> phone_num;
	std::cout << "Enter darkest secret\n";
	std::cin >> darkest_secret;
	if (!first_name.length() || !last_name.length() || !nickname.length()
		| !phone_num.length() || !darkest_secret.length())
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
}

bool	Contact::ContactEmpty()
{
	if (phone_num == "")
		return (true);
	return(false);
}

void	Contact::PrintContact()
{
	std::cout << std::endl;
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone_num << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
	std::cout << std::endl;
}
