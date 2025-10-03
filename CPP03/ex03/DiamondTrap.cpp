
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name_(name)
{
	// Attributes: HP from FragTrap, EP from ScavTrap, AD from FragTrap
	hitPoints_ = 100;		// FragTrap's HP
	energyPoints_ = 50;		// ScavTrap's EP
	attackDamage_ = 30;		// FragTrap's AD
	std::cout << "DiamondTrap ctor: " << name_ << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name_(other.name_)
{
	std::cout << "DiamondTrap copy-ctor: " << name_ << "\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		// ScavTrap/FragTrap do not add data beyond ClapTrap here
		name_ = other.name_;
	}
	std::cout << "DiamondTrap copy-assign: " << name_ << "\n";
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap dtor: " << name_ << "\n";
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name_ << " | ClapTrap name: " << ClapTrap::name_ << "\n";
}
