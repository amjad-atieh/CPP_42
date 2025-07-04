/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:15:03 by aatieh            #+#    #+#             */
/*   Updated: 2025/06/10 16:23:49 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	std::string input;

	if (ac != 2)
	{
		std::cerr << "Wrong format\nThe correct format is ./program argument" << std::endl;
		return 1;
	}
	input = av[1];
	ScalarConverter::convert(input);
	return 0;
}
