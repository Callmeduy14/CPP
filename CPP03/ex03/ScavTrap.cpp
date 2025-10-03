/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:08:39 by yyudi             #+#    #+#             */
/*   Updated: 2025/10/03 10:08:40 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout << "ScavTrap ctor: " << name_ << "\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy-ctor: " << name_ << "\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap copy-assign: " << name_ << "\n";
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap dtor: " << name_ << "\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints_ == 0 || energyPoints_ == 0)
	{
		std::cout << "ScavTrap " << name_ << " can't attack (no HP/EP)\n";
		return;
	}
	--energyPoints_;
	std::cout << "ScavTrap " << name_ << " slashes " << target
			  << " for " << attackDamage_ << " damage!\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode.\n";
}
