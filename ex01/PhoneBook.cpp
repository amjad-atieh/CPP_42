/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:49:38 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/18 05:12:58 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class PhoneBook
{
private:
	std::string contact[8];
	int			contact_num = 1;
public:
	void AddPhoneBook(std::string new_contact);
	~PhoneBook();
};

void PhoneBook::AddPhoneBook(std::string new_contact)
{
	if (contact_num)
}

PhoneBook::~PhoneBook()
{
}


int	main(void)
{
	std::string string1;
	int			contact_num;

	while(1)
	{
		std::cin >> string1;
		if (string1 == "Hello")
			break ;
		std::cout << string1 << std::endl;
	}
	return 0;
}
