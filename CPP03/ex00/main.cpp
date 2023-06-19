/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:02:56 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 15:14:20 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap p1("Alice");
	ClapTrap p2("Bob");

	p1.attack("Bob");
	p2.takeDamage(3);
	p2.beRepaired(5);

	p2.attack("Alice");
	p1.takeDamage(3);
	p1.beRepaired(5);
	return 0;
}
