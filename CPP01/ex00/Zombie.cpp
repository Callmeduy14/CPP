/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:54:20 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 17:54:27 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name_("") {}

Zombie::Zombie(const std::string &name) : name_(name) {}

Zombie::~Zombie() {
	std::cout << name_ << " destroyed!" << std::endl;
}

void Zombie::announce(void) const {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
	name_ = name;
}
