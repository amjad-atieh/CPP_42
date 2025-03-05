/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:01:59 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/05 17:50:37 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	{
		ClapTrap robot1("K9");
		ClapTrap robot2("6-XE");

		robot1.attack("6-XE");
		robot2.takeDamage(2);
		robot2.beRepaired(2);
		robot2.attack("K9");
		robot1.takeDamage(2);
		robot1.beRepaired(2);
		robot1.beRepaired(2);
		robot1.takeDamage(12);
		robot1.takeDamage(2);
	}
	{
		ScavTrap robot1("M9");
		ScavTrap robot2("6-JA");

		robot1.attack("6-JA");
		robot2.guardGate();
		robot2.takeDamage(20);
		robot2.beRepaired(20);
		robot2.attack("M9");
		robot1.beRepaired(20);
		robot1.beRepaired(20);
		robot1.takeDamage(120);
		robot1.takeDamage(20);
	}
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
	}
	return 0;
}
