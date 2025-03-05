#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : claptrap()
{
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
	claptrap.setHitpoints(SCAV_MAX_HITPOINTS);
	claptrap.setEnergyPoints(SCAV_MAX_ENERGYPOINTS);
	claptrap.setAttackDamage(20);
	isGuardGate = false;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : claptrap(copy.getClaptrap())
{
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
	isGuardGate = copy.getIsGuardGate();
}

ScavTrap::ScavTrap(std::string name) : claptrap(name)
{
	std::cout << "\e[0;33mConstructor called of ScavTrap\e[0m" << std::endl;
	claptrap.setHitpoints(SCAV_MAX_HITPOINTS);
	claptrap.setEnergyPoints(SCAV_MAX_ENERGYPOINTS);
	claptrap.setAttackDamage(20);
	isGuardGate = false;
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
	isGuardGate = assign.getIsGuardGate();
	claptrap = assign.getClaptrap();
	return *this;
}

// Member functions
ClapTrap	ScavTrap::getClaptrap() const
{
	return claptrap;
}

bool	ScavTrap::getIsGuardGate() const
{
	return isGuardGate;
}

void	ScavTrap::guardGate()
{
	if (!claptrap.getEnergyPoints())
	{
		std::cout << "\e[0;31mScavTrap " << claptrap.getName()
			<< " is out of energy!\e[0m" << std::endl;
		return ;
	}
	if (!isGuardGate)
	{
		isGuardGate = true;
		std::cout << "\e[0;34mScavTrap " << claptrap.getName()
			<< " has entered in Gate keeper mode\e[0m" << std::endl;
	}
	else
	{
		isGuardGate = false;
		std::cout << "\e[0;34mScavTrap " << claptrap.getName()
			<< " has exited from Gate keeper mode\e[0m" << std::endl;
	}
}

void	ScavTrap::attack(std::string const &target)
{
	if (!isGuardGate)
		claptrap.attack(target);
	else
		std::cout << "\e[0;31mScavTrap " << claptrap.getName()
			<< " is in Gate keeper mode and can't attack\e[0m" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (!isGuardGate || (isGuardGate && !claptrap.getEnergyPoints()))
	{
		if (isGuardGate && !claptrap.getEnergyPoints())
			std::cout << "\e[0;31mScavTrap " << claptrap.getName()
				<< " is in Gate keeper mode but has no energy to defend\e[0m" << std::endl;
		claptrap.takeDamage(amount);
	}
	else if (isGuardGate && claptrap.getEnergyPoints())
	{
		if (amount > claptrap.getEnergyPoints())
			amount = claptrap.getEnergyPoints();
		std::cout << "\e[0;31mScavTrap " << claptrap.getName()
			<< " is in Gate keeper mode and " << amount
			<< " points of damage was dealt on its energy\e[0m" << std::endl;
		claptrap.setEnergyPoints(claptrap.getEnergyPoints() - amount);
		if (!claptrap.getEnergyPoints())
			std::cout << "\e[0;31mScavTrap " << claptrap.getName()
				<< " is out of energy!\e[0m" << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	claptrap.beRepaired(amount);
}
