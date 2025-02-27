/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:26:49 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/27 18:49:21 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

Zombie::Zombie()
{
}

Zombie::Zombie( std::string name )
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "all of the " << name << "s have been destroyed\n";
}

void	Zombie::announce( void )
{
	std::cout << name << " BraiiiiiiinnnzzzZ...\n";
}
