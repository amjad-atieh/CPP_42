/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:25:27 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/02 17:16:06 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

int	main()
{
	Zombie*	zombie = NULL;
	int		n;

	std::cout << "Enter the number of zombies you want to create: ";
	std::cin >> n;
	if (n < 1)
	{
		std::cerr << "Invalid number of zombies!\n";
		return 0;
	}
	zombie = zombie->zombieHorde(n, "Tom");
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Zombie " << i + 1 << ": ";
		zombie[i].announce();
	}
	operator delete[] (zombie);
	return 0;
}
