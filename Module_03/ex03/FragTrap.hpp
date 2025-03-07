/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:36 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/07 16:47:57 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

# define FRAG_DEF_HITPOINTS 100
# define FRAG_DEF_ENERGYPOINTS 100
# define FRAG_ATTACK_DAMAGE 30

class FragTrap : virtual public ClapTrap
{
	public:

		// Constructors
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);

		// Destructor
		~FragTrap();

		// Operators
		FragTrap & operator=(const FragTrap &assign);

		// Member functions
		void		highFivesGuys(void);

};

#endif