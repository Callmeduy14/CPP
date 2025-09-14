/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:55:08 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 17:55:09 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 5;
	Zombie* horde = zombieHorde(N, "HordeZombie");
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}
	delete [] horde;
	return 0;
}
