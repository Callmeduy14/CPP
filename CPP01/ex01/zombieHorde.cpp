/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:56:26 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 17:56:27 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string &name) {
	if (N <= 0) return 0;
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
	}
	return horde;
}
