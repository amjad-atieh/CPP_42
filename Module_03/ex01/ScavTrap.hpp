/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:25:55 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/07 11:42:35 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

# define SCAV_DEF_HITPOINTS 100
# define SCAV_DEF_ENERGYPOINTS 50
# define SCAV_ATTACK_DAMAGE 20

class ScavTrap : public ClapTrap
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
		void	guardGate();
		void	attack(std::string const &target);

};

#endif