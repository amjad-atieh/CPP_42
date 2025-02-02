/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:45:31 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/02 17:37:54 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (weapon)
	{
		std::cout << name << " attaked with a "
			<< (*weapon).getType() << '\n';
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
