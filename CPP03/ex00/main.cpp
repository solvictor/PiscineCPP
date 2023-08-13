/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:02:56 by vegret            #+#    #+#             */
/*   Updated: 2023/08/13 19:21:12 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap joe("Joe");
	ClapTrap bill("Bill");
	ClapTrap cpy(joe);

	bill.attack("Joe");
	joe.beRepaired(10);
	cpy.takeDamage(10);
	joe.takeDamage(10);
	joe.takeDamage(10);
	joe.attack("Bill");

	return 0;
}
