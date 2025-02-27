/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:26:01 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/27 20:29:44 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
				Zombie();
				~Zombie();
				Zombie( std::string name );
		void	announce( void );
		Zombie*	zombieHorde( int N, std::string name );

	private:
		std::string name;
};

#endif
