/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:44:52 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/20 08:57:34 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string weapon_type )
{
	type = weapon_type;
}

std::string	Weapon::getType() const
{
	return type;
}

void	Weapon::setType( std::string weapon_type )
{
	type = weapon_type;
}

Weapon::~Weapon()
{
}
