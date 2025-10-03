/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:19:35 by yyudi             #+#    #+#             */
/*   Updated: 2025/10/03 10:19:36 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cctype>

int main(int argc, char** argv) {
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			const char* s = argv[i];
			for (int j = 0; s[j]; ++j) {
				unsigned char ch = static_cast<unsigned char>(s[j]);
				std::cout << static_cast<char>(std::toupper(ch));
			}
			if (i + 1 < argc) std::cout << " ";
		}
		std::cout << std::endl;
	} else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return 0;
}
