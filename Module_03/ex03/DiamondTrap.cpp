#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of DiamondTrap\e[0m" << std::endl;
}


// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31mDestructor called of DiamondTrap\e[0m" << std::endl;
}


// Operators
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &assign)
{
	(void) assign;
	return *this;
}

