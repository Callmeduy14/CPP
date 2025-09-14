/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:10:26 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 18:10:37 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

static int levelIndex(const std::string &level) {
	if (level == "DEBUG") return 0;
	if (level == "INFO") return 1;
	if (level == "WARNING") return 2;
	if (level == "ERROR") return 3;
	return -1;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}
	std::string level = argv[1];
	int idx = levelIndex(level);

	Harl h;
	switch (idx) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			h.complain("DEBUG");

		case 1:
			std::cout << "[ INFO ]" << std::endl;
			h.complain("INFO");

		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			h.complain("WARNING");

		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			h.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}
