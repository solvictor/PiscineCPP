/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:25:29 by vegret            #+#    #+#             */
/*   Updated: 2023/07/05 01:13:33 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("no_name_clap_name"), ScavTrap(), FragTrap()
{	
	std::cout << "DiamondTrap default constructor call" << std::endl;
	this->hit = FragTrap::hit;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap name constructor call" << std::endl;
	this->name = name;
	this->hit = FragTrap::hit;
	this->damage = FragTrap::damage;
	this->energy = ScavTrap::energy;
}

DiamondTrap::DiamondTrap(const DiamondTrap &source) : ClapTrap(source), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap copy constructor call" << std::endl;
	*this = source;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor call" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &source)
{
	ClapTrap::operator=(source);
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	if (this->energy > 0 && this->hit > 0)
		std::cout << "I am " << this->name << " and " << ClapTrap::name << std::endl;
}
