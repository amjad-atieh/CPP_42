/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:25:27 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/27 18:37:56 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombie_assigner(std::string name)
{
	Zombie* heap_zombie = NULL;

	heap_zombie = heap_zombie->newZombie(name);
	return (heap_zombie);
}

int main()
{
	Zombie	*zombie = NULL;

	zombie->randomChump("Ahmad");
	zombie = zombie_assigner("Alia");
	zombie->announce();
	delete zombie;
	return 0;
}
