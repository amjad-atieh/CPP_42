/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:10:01 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/03 18:15:11 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde( int numZombies, std::string name )
{
	void	*memory;
	Zombie	*zombies;

	memory = operator new[](numZombies * sizeof(Zombie), (std::nothrow));
	if (!memory)
	{
		std::cerr << "Memory allocation failed!\n";
		return NULL;
	}
	zombies = static_cast<Zombie *>(memory);
	for (int i = 0; i < numZombies; ++i)
		new (&zombies[i]) Zombie(name);
	return zombies;
}
