/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:06:14 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 18:06:15 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
	std::string name_;
	Weapon *weapon_;
public:
	explicit HumanB(const std::string &name);
	void setWeapon(Weapon &weapon);
	void attack() const;
};

#endif 
