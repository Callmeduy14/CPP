/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:08:19 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 18:08:20 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	const std::string filename = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];

	if (!FileReplace::replaceInFile(filename, s1, s2)) {
		std::cerr << "Error: cannot process file." << std::endl;
		return 1;
	}
	return 0;
}
