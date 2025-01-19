/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:26:01 by aatieh            #+#    #+#             */
/*   Updated: 2025/01/19 07:29:42 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	/* data */
public:
	Zombie(/* args */);
	~Zombie();
	Zombie* zombieHorde( int N, std::string name );
};

Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
}


#endif
