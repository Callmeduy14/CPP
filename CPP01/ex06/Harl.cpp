/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:09:55 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 18:09:56 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
	std::cout << "DEBUG: Contextual info\n";
}
void Harl::info(void) {
	std::cout << "INFO: Tracing execution\n";
}
void Harl::warning(void) {
	std::cout << "WARNING: Potential issue detected\n";
}
void Harl::error(void) {
	std::cout << "ERROR: Unrecoverable error occurred\n";
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
