/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:25:39 by aatieh            #+#    #+#             */
/*   Updated: 2025/05/24 21:21:57 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange	data;

	if (ac != 2)
	{
		std::cerr << "Error: incorret format\n"
			<<"The correct format is ./btc file_name" << std::endl;
		return 1;
	}
	try
	{
		data.readFile(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 2;
	}
	std::string	date;
	float		value;

	while (1)
	{
		std::cout << "Enter date: ";
		std::getline(std::cin, date);
		if (std::cin.fail() || std::cin.eof() || std::cin.bad())
			break ;
		value = data.dateValue(date);
		if (value != -1)
			std::cout << "value: " << value << std::endl;
	}
	return 0;
}
