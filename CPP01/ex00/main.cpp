/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:52:39 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/01 17:52:40 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie a("StackZombie");
	a.announce();

	Zombie* b = newZombie("HeapZombie");
	b->announce();
	delete b;

	randomChump("RandomStackZombie");
	return 0;
}
