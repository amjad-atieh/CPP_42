/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:02:08 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/12 19:05:19 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define CLAP_DEF_HITPOINTS 10
# define CLAP_DEF_ENERGYPOINTS 10
# define CLAP_DEF_ATTACK 0

class ClapTrap
{
	public:

		// Constructors
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string name);
		ClapTrap(unsigned int hitpoints, unsigned int energyPoints,
			unsigned int attackDamage);
		ClapTrap(std::string name, unsigned int hitpoints, unsigned int energyPoints,
			unsigned int attackDamage);

		// Destructor
		~ClapTrap();

		// Operators
		ClapTrap & operator=(const ClapTrap &assign);

		// Getters
		std::string		getName() const;
		unsigned int	getHitpoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;

		// Setters
		void			setEnergyPoints(unsigned int amount);
		void			setHitpoints(unsigned int amount);
		void			setAttackDamage(unsigned int amount);
		
		// Member functions
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