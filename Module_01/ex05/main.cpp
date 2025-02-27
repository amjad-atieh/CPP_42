/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:29:14 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/18 20:04:18 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	for (int i = 1; i < argc; i++)
		harl.complain(argv[i]);
	if (argc == 1)
		harl.complain("RANDOM");
	return 0;
}
