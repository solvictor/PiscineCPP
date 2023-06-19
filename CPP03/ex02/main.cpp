/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:02:56 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 16:24:05 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main()
{
    FragTrap robot("Garf");

    robot.attack("Enemy");
    robot.takeDamage(10);
    robot.beRepaired(5);
    robot.highFivesGuys();
	
	return 0;
}
