/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:01:59 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/07 17:26:19 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	robot1("Dave");

	std::cout << "diamondTrap damage: " << robot1.getAttackDamage() << std::endl;
	std::cout << "diamondTrap hitpoints: " << robot1.getHitpoints() << std::endl;
	std::cout << "diamondTrap energy points: " << robot1.getEnergyPoints() << std::endl;
	robot1.attack("target");
	robot1.takeDamage(10);
	robot1.beRepaired(10);
	robot1.takeDamage(110);
	robot1.guardGate();
	robot1.highFivesGuys();
	robot1.whoAmI();
	return 0;
}
