/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:25:39 by aatieh            #+#    #+#             */
/*   Updated: 2025/08/07 19:25:56 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	// BitcoinExchange	data;

	// if (ac != 3)
	// {
	// 	std::cerr << "Error: incorret format\n"
	// 		<<"The correct format is ./btc price_data_base input_data_base" << std::endl;
	// 	return 1;
	// }
	// try
	// {
	// 	data.readFile(av[1]);
	// 	data.takeInput(av[2]);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// 	return 2;
	// }
	
	// std::string	date;
	// float		value;

	// while (1)
	// {
	// 	std::cout << "Enter date: ";
	// 	std::getline(std::cin, date);
	// 	if (std::cin.fail() || std::cin.eof() || std::cin.bad())
	// 		break ;
	// 	value = data.dateValue(date);
	// 	if (value != -1)
	// 		std::cout << "value: " << value << std::endl;
	// }
	(void)ac;
	BitcoinExchange a;
	// std::string b(av[1]);
	try
	{
		a.addData("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in the data file" << std::endl;
		return 1;
	}
	
	a.takeInput(av[1]);
	return 0;
}
