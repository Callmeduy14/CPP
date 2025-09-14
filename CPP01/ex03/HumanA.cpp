/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:05:19 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 18:05:20 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon)
	: name_(name), weapon_(weapon) {}

void HumanA::attack() const {
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
