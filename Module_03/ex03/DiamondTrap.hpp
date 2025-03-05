#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap
{
	public:

		// Constructors
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);

		// Destructor
		~DiamondTrap();

		// Operators
		DiamondTrap & operator=(const DiamondTrap &assign);

		// Member functions
		void	whoAmI(void);
		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	private:

		std::string name;
};

#endif