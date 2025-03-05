/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:36 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/05 11:08:28 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

# define FRAG_MAX_HITPOINTS 100
# define FRAG_MAX_ENERGYPOINTS 100

class FragTrap
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
		ClapTrap	getClaptrap() const;
	
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		highFivesGuys(void);

	private:

		ClapTrap	claptrap;
};

#endif