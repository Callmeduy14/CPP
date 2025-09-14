/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:56:15 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 17:56:16 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
	std::string name_;
public:
	Zombie();
	explicit Zombie(const std::string &name);
	~Zombie();
	void announce(void) const;
	void setName(const std::string &name);
};

Zombie* zombieHorde(int N, const std::string &name);

#endif
