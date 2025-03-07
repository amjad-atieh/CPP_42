/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:39 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/07 12:53:09 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap(FRAG_DEF_HITPOINTS,
				FRAG_DEF_ENERGYPOINTS, FRAG_ATTACK_DAMAGE)
{
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, FRAG_DEF_HITPOINTS,
								FRAG_DEF_ENERGYPOINTS, FRAG_ATTACK_DAMAGE)
{
	std::cout << "\e[0;33mConstructor called of FragTrap\e[0m" << std::endl;
}


// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}


// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	std::cout << "\e[0;33mAssignation operator called of FragTrap\e[0m" << std::endl;
	ClapTrap::operator=(assign);
	return *this;
}

// Member functions
void	FragTrap::highFivesGuys(void)
{
	if (getHitpoints() && getEnergyPoints())
	{
		std::cout << "\e[0;32mFragTrap " << getName()
			<< " says can I get a high five!!\e[0m" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
		setHitpoints(getHitpoints() + 1);
	}
	else if (!getHitpoints())
		std::cout << "\e[0;31mFragTrap " << getName()
			<< " doesn't have enough fingers to high five!\e[0m" << std::endl;
	else
	{
		std::cout << "\e[0;31mFragTrap " << getName()
			<< " is out of energy to high five!\e[0m" << std::endl;
	}
}
