
#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Alpha");
	a.attack("target");
	a.takeDamage(3);
	a.beRepaired(2);
	a.takeDamage(20);
	a.attack("nobody");
	return 0;
}
