/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:08:06 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 18:08:07 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACE_HPP
#define FILEREPLACE_HPP

#include <string>

class FileReplace {
public:
	static bool replaceInFile(const std::string &filename,
							  const std::string &s1,
							  const std::string &s2);
};

#endif 
