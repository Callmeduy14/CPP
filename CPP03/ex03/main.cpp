
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap d("Dia");
	d.attack("training dummy"); // should use ScavTrap's attack
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();
	d.takeDamage(40);
	d.beRepaired(20);
	return 0;
}
