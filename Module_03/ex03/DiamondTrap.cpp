#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap() : ClapTrap("common_ClapTrap_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of DiamondTrap\e[0m" << std::endl;
	name = "common_DiamondTrap";
	setHitpoints(FRAG_DEF_HITPOINTS);
	setEnergyPoints(SCAV_DEF_ENERGYPOINTS);
	setAttackDamage(FRAG_ATTACK_DAMAGE);
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) :  ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "\e[0;33mConstructor called of DiamondTrap\e[0m" << std::endl;
	this->name = name;
	setHitpoints(FRAG_DEF_HITPOINTS);
	setEnergyPoints(SCAV_DEF_ENERGYPOINTS);
	setAttackDamage(FRAG_ATTACK_DAMAGE);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31mDestructor called of DiamondTrap\e[0m" << std::endl;
}


// Operators
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &assign)
{
	std::cout << "\e[0;33mAssignation operator called of DiamondTrap\e[0m" << std::endl;
	ScavTrap::operator=(assign);
	FragTrap::operator=(assign);
	return *this;
}

// Member functions
void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::getName() << std::endl;
}
