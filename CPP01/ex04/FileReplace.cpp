/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:07:52 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 18:07:53 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"
#include <fstream>
#include <sstream>

static std::string replaceAllManual(const std::string &input,
									const std::string &s1,
									const std::string &s2) {
	if (s1.empty()) return input;
	std::string out;
	out.reserve(input.size());
	std::string::size_type pos = 0;
	while (true) {
		std::string::size_type found = input.find(s1, pos);
		if (found == std::string::npos) {
			out.append(input, pos, std::string::npos);
			break;
		}
		out.append(input, pos, found - pos);
		out.append(s2);
		pos = found + s1.size();
	}
	return out;
}

bool FileReplace::replaceInFile(const std::string &filename,
								const std::string &s1,
								const std::string &s2) {
	std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary);
	if (!in) return false;

	std::ostringstream buffer;
	buffer << in.rdbuf();
	std::string content = buffer.str();
	in.close();

	std::string replaced = replaceAllManual(content, s1, s2);

	std::ofstream out((filename + ".replace").c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
	if (!out) return false;
	out.write(replaced.c_str(), static_cast<std::streamsize>(replaced.size()));
	out.close();
	return true;
}
