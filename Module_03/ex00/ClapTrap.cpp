/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:02:06 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/12 18:28:36 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
	name = "common_ClapTrap";
	hitpoints = DEF_HITPOINTS;
	energyPoints = DEF_ENERGYPOINTS;
	attackDamage = DEF_ATTACK;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	name = copy.getName();
	hitpoints = copy.getHitpoints();
	energyPoints = copy.getEnergyPoints();
	attackDamage = copy.getAttackDamage();
	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "\e[0;33mConstructor called of ClapTrap\e[0m" << std::endl;
	this->name = name;
	hitpoints = DEF_HITPOINTS;
	energyPoints = DEF_ENERGYPOINTS;
	attackDamage = DEF_ATTACK;
}


// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
}


// Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	std::cout << "\e[0;33mAssignation operator called of ClapTrap\e[0m" << std::endl;
	name = assign.getName();
	hitpoints = assign.getHitpoints();
	energyPoints = assign.getEnergyPoints();
	attackDamage = assign.getAttackDamage();
	return *this;
}

// Member functions
std::string	ClapTrap::getName() const
{
	return name;
}

unsigned int	ClapTrap::getHitpoints() const
{
	return hitpoints;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return attackDamage;
}

void	ClapTrap::attack(std::string const &target)
{
	if (energyPoints && hitpoints)
	{
		std::cout << "\e[0;32mClapTrap " << name << " attacks " << target
			<< " causing " << attackDamage << " points of damage!\e[0m" << std::endl;
		energyPoints--;
		if (!energyPoints)
			std::cout << "\e[0;31mClapTrap " << name
				<< " is out of energy!\e[0m" << std::endl;
	}
	else if (!hitpoints)
		std::cout << "\e[0;31mClapTrap " << name
			<< " is too damaged to attack!\e[0m" << std::endl;
	else
		std::cout << "\e[0;31mClapTrap " << name
			<< " doesn't have the energy to attack\e[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hitpoints)
		amount = hitpoints;
	if (hitpoints)
	{
		hitpoints -= amount;
		std::cout << "\e[0;31mClapTrap " << name << " takes "
			<< amount << " points of damage!\e[0m" << std::endl;
		if (!hitpoints)
			std::cout << "\e[0;31mClapTrap " << name
				<< " has been destroyed!\e[0m" << std::endl;
	}
	else
		std::cout << "\e[0;31mClapTrap " << name
			<< " is already too damaged to take more damage!\e[0m" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!hitpoints)
	{
		std::cout << "\e[0;31mClapTrap " << name
			<< " is already destroyed!\e[0m" << std::endl;
		return ;
	}
	if (hitpoints + amount > DEF_HITPOINTS)
		amount = DEF_HITPOINTS - hitpoints;
	if (energyPoints && hitpoints < DEF_HITPOINTS)
	{
		std::cout << "\e[0;34mClapTrap " << name << " has been repaired by "
			<< amount << " points!\e[0m" << std::endl;
		energyPoints--;
		hitpoints += amount;
		if (!energyPoints)
			std::cout << "\e[0;31mClapTrap " << name
				<< " is out of energy!\e[0m" << std::endl;
	}
	else if (!energyPoints)
		std::cout << "\e[0;31mClapTrap " << name
			<< " doesn't have the energy to be repaired\e[0m" << std::endl;
	else
		std::cout << "\e[0;31mClapTrap " << name
			<< " is already at full health\e[0m" << std::endl;
}
