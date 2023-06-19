/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:02:56 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 16:14:25 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	ClapTrap yay;
	ClapTrap joe("Joe");
	ClapTrap bill("Bill");
	ScavTrap willfried("Willfried");
	ScavTrap yay2;

	std::cout << std::endl;

	willfried.attack("Joe");
	willfried.guardGate();
	bill.attack("Joe");
	joe.beRepaired(10);
	joe.takeDamage(10);
	joe.attack("Bill");
	yay.attack("Willfried");
	yay2.takeDamage(200);

	//Can't do because he don't have health anymore
	yay2.beRepaired(100);
	yay2.guardGate();

	std::cout << std::endl;
	
	return 0;
}
