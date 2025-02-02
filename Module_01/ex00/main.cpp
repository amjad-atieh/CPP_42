/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:25:27 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/02 05:28:04 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie*	zombie1 = NULL;

	zombie1 = zombie1->newZombie("Tod");
	zombie1->randomChump("Bob");
	zombie1->announce();
	delete zombie1;
	return 0;
}
