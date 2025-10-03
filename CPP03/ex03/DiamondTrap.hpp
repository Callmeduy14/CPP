/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:13:51 by yyudi             #+#    #+#             */
/*   Updated: 2025/10/03 10:13:52 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	using ScavTrap::attack; // use ScavTrap's attack
	void whoAmI();

private:
	std::string name_; // same variable name as ClapTrap
};

#endif 
