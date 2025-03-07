#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap(SCAV_DEF_HITPOINTS,
						SCAV_DEF_ENERGYPOINTS, SCAV_ATTACK_DAMAGE)
{
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, SCAV_DEF_HITPOINTS,
										SCAV_DEF_ENERGYPOINTS, SCAV_ATTACK_DAMAGE)
{
	std::cout << "\e[0;33mConstructor called of ScavTrap\e[0m" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}


// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	std::cout << "\e[0;33mAssignation operator called of ScavTrap\e[0m" << std::endl;
	ClapTrap::operator=(assign);
	return *this;
}

// Member functions
void	ScavTrap::guardGate()
{
	std::cout << "\e[0;34mScavTrap " << getName()
		<< " has entered in Gate keeper mode\e[0m" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (getEnergyPoints())
	{
		std::cout << "\e[0;32mScavTrap " << getName() << " attacks " << target
			<< " causing " << getAttackDamage() << " points of damage!\e[0m" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else
	{
		std::cout << "\e[0;31mScavTrap " << getName()
			<< " is out of energy!\e[0m" << std::endl;
	}
}
