/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:07:09 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 18:07:10 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type_(type) {}

const std::string& Weapon::getType() const {
	return type_;
}

void Weapon::setType(const std::string &type) {
	type_ = type;
}
