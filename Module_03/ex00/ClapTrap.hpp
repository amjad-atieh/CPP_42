/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:02:08 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/12 18:28:24 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define DEF_HITPOINTS 10
# define DEF_ENERGYPOINTS 10
# define DEF_ATTACK 0

class ClapTrap
{
	public:

		// Constructors
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string name);

		// Destructor
		~ClapTrap();

		// Operators
		ClapTrap & operator=(const ClapTrap &assign);

		// Member functions
		std::string		getName() const;
		unsigned int	getHitpoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:

		std::string		name;
		unsigned int	hitpoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
};

#endif