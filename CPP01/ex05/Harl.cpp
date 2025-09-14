/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:09:13 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 18:09:14 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl;
}
void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years." << std::endl;
}
void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string &level) {
	typedef void (Harl::*Fn)();
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Fn fns[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; ++i) {
		if (levels[i] == level) {
			(this->*fns[i])();
			return;
		}
	}
}
