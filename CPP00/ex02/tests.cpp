/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:21:34 by yyudi             #+#    #+#             */
/*   Updated: 2025/10/03 10:21:35 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"
#include <vector>
#include <cstdlib>

int main(void) {
	{
		Account a(42);
		Account b(100);
		Account c(0);

		Account::displayAccountsInfos();
		a.displayStatus();
		b.displayStatus();
		c.displayStatus();

		a.makeDeposit(5);
		b.makeDeposit(10);
		c.makeDeposit(3);

		a.makeWithdrawal(20);
		b.makeWithdrawal(200);
		c.makeWithdrawal(1);

		Account::displayAccountsInfos();
		a.displayStatus();
		b.displayStatus();
		c.displayStatus();
	}
	Account::displayAccountsInfos();
	return 0;
}
