/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:01:59 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/12 19:22:11 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	FragTrap robot1("F9");
	FragTrap robot2("6-JA");

	robot1.attack("6-JA");
	robot2.highFivesGuys();
	robot2.takeDamage(20);
	robot2.beRepaired(20);
	robot2.attack("F9");
	robot1.takeDamage(20);
	robot1.takeDamage(120);
	robot1.beRepaired(20);
	return 0;
}
