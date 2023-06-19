/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:02:56 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 17:15:53 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap joe("Joe");
	std::cout << std::endl;
	ClapTrap yay;
	std::cout << std::endl;
	ScavTrap willfried("Willfried");
	std::cout << std::endl;
	ScavTrap yay2;
	std::cout << std::endl;
	FragTrap bill("Bill");
	std::cout << std::endl;
	FragTrap yay3;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FlagTrap" << std::endl;
	bill.attack("Willfried");
	bill.highFivesGuys();
	bill.takeDamage(200);
	bill.highFivesGuys();
	yay3.takeDamage(100);

	std::cout << std::endl;
	std::cout << "ScavTrap" << std::endl;
	willfried.attack("Joe");
	willfried.guardGate();
	yay2.takeDamage(200);
	yay2.beRepaired(100);
	yay2.guardGate();

	std::cout << std::endl;
	std::cout << "ClapTrap" << std::endl;
	joe.beRepaired(10);
	joe.takeDamage(10);
	joe.attack("Bill");
	yay.attack("Willfried");

	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
