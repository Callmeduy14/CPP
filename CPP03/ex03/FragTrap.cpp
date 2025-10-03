/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:10:12 by yyudi             #+#    #+#             */
/*   Updated: 2025/10/03 10:10:13 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout << "FragTrap ctor: " << name_ << "\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy-ctor: " << name_ << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap copy-assign: " << name_ << "\n";
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap dtor: " << name_ << "\n";
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name_ << " requests high fives! ✋\n";
}
