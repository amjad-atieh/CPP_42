/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:26:49 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/02 06:18:25 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

Zombie::Zombie()
{
}

Zombie::Zombie( std::string name )
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "all of the " << name << "s have been destroyed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	Zombie::zombieHorde( int numZombies, std::string name )
{
	void	*memory;
	Zombie	*zombies;

	memory = operator new[](numZombies * sizeof(Zombie), (std::nothrow));
	if (!memory)
	{
		std::cerr << "Memory allocation failed!" << std::endl;
		return NULL;
	}
	zombies = static_cast<Zombie *>(memory);
	for (int i = 0; i < numZombies; ++i)
		new (&zombies[i]) Zombie(name);
	return zombies;
}
