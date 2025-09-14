/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:54:03 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 17:54:11 by yyudi            ###   ########.fr       */
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

Zombie* newZombie(const std::string &name);
void randomChump(const std::string &name);

#endif
