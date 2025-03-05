/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:55 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/05 10:34:41 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

# define SCAV_MAX_HITPOINTS 100
# define SCAV_MAX_ENERGYPOINTS 50

class ScavTrap
{
	public:

		// Constructors
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);

		// Destructor
		~ScavTrap();

		// Operators
		ScavTrap & operator=(const ScavTrap &assign);

		// Member functions
		ClapTrap	getClaptrap() const;
		bool		getIsGuardGate() const;

		void	guardGate();
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:

	ClapTrap		claptrap;
	bool			isGuardGate;

};

#endif