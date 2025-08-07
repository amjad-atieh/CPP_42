/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:25:39 by aatieh            #+#    #+#             */
/*   Updated: 2025/08/07 19:46:04 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	BitcoinExchange a;

	if (ac != 2)
	{
		std::cerr << "Incorrect format\nThe correct format is ./btc inputFile" << std::endl;
		return 1;	
	}
	try
	{
		a.addData("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in the data file" << std::endl;
		return 1;
	}

	try
	{
		a.takeInput(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
