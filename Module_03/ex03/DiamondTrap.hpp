#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		// Constructors
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);

		// Destructor
		~DiamondTrap();

		// Operators
		DiamondTrap & operator=(const DiamondTrap &assign);

		// Member functions
		void	whoAmI(void);

	private:

		std::string name;
};

#endif