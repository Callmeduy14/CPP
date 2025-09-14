/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:05:48 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 18:05:49 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
	: name_(name), weapon_(0) {}

void HumanB::setWeapon(Weapon &weapon) {
	weapon_ = &weapon;
}

void HumanB::attack() const {
	if (weapon_) {
		std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
	} else {
		std::cout << name_ << " has no weapon" << std::endl;
	}
}
