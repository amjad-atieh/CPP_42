/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:39 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/05 11:20:56 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : claptrap()
{
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
	claptrap.setHitpoints(FRAG_MAX_HITPOINTS);
	claptrap.setEnergyPoints(FRAG_MAX_ENERGYPOINTS);
	claptrap.setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &copy) : claptrap(copy.getClaptrap())
{
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : claptrap(name)
{
	std::cout << "\e[0;33mConstructor called of FragTrap\e[0m" << std::endl;
	claptrap.setHitpoints(FRAG_MAX_HITPOINTS);
	claptrap.setEnergyPoints(FRAG_MAX_ENERGYPOINTS);
	claptrap.setAttackDamage(30);
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
	claptrap = assign.getClaptrap();
	return *this;
}

// Member functions
ClapTrap	FragTrap::getClaptrap() const
{
	return claptrap;
}

void	FragTrap::highFivesGuys(void)
{
	if (claptrap.getHitpoints() && claptrap.getEnergyPoints())
	{
		std::cout << "\e[0;32mFragTrap " << claptrap.getName()
			<< " says can I get a high five!!\e[0m" << std::endl;
		claptrap.setEnergyPoints(claptrap.getEnergyPoints() - 1);
		claptrap.setHitpoints(claptrap.getHitpoints() + 1);
	}
	else if (!claptrap.getHitpoints())
		std::cout << "\e[0;31mFragTrap " << claptrap.getName()
			<< " doesn't have enough fingers to high five!\e[0m" << std::endl;
	else
	{
		std::cout << "\e[0;31mFragTrap " << claptrap.getName()
			<< " is out of energy to high five!\e[0m" << std::endl;
	}
}

void	FragTrap::attack(std::string const &target)
{
	claptrap.attack(target);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	claptrap.takeDamage(amount);
}

void	FragTrap::beRepaired(unsigned int amount)
{
	claptrap.beRepaired(amount);
}
