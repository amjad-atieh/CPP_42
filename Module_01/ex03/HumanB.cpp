/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:45:31 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/20 09:05:39 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (weapon)
	{
		std::cout << name << " attaked with a "
			<< (*weapon).getType() << std::endl;
	}
	else
		std::cout << name << " doesn't have a weapon to attack with\n";
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}

HumanB::HumanB( std::string	name )
{
	this->name = name;
	weapon = NULL;
}

HumanB::~HumanB()
{
}
