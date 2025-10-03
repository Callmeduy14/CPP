/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:06:37 by yyudi             #+#    #+#             */
/*   Updated: 2025/10/03 10:06:38 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
	std::cout << "ClapTrap ctor: " << name_ << " online\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) : name_(other.name_), hitPoints_(other.hitPoints_), energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_)
{
	std::cout << "ClapTrap copy-ctor: " << name_ << "\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	std::cout << "ClapTrap copy-assign: " << name_ << "\n";
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap dtor: " << name_ << " offline\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints_ == 0 || energyPoints_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " can't attack (no HP/EP)\n";
		return;
	}
	--energyPoints_;
	std::cout << "ClapTrap " << name_ << " attacks " << target
			  << ", causing " << attackDamage_ << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " is already at 0 HP\n";
		return;
	}
	unsigned int old = hitPoints_;
	hitPoints_ = (amount >= hitPoints_) ? 0 : (hitPoints_ - amount);
	std::cout << "ClapTrap " << name_ << " takes " << amount
			  << " damage (HP " << old << " -> " << hitPoints_ << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints_ == 0 || energyPoints_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " can't repair (no HP/EP)\n";
		return;
	}
	--energyPoints_;
	hitPoints_ += amount;
	std::cout << "ClapTrap " << name_ << " repairs " << amount
			  << " HP (now " << hitPoints_ << ")\n";
}
