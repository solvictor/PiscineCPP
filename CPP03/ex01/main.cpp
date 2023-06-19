/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:02:56 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 17:16:57 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	ClapTrap yay;
	std::cout << std::endl;
	ClapTrap joe("Joe");
	std::cout << std::endl;
	ClapTrap bill("Bill");
	std::cout << std::endl;
	ScavTrap willfried("Willfried");
	std::cout << std::endl;
	ScavTrap yay2;

	std::cout << std::endl;
	std::cout << std::endl;

	willfried.attack("Joe");
	willfried.guardGate();
	bill.attack("Joe");
	joe.beRepaired(10);
	joe.takeDamage(10);
	joe.attack("Bill");
	yay.attack("Willfried");
	yay2.takeDamage(200);

	// No health
	yay2.beRepaired(100);
	yay2.guardGate();

	std::cout << std::endl;

	return 0;
}
