/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:44:52 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 15:23:19 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("No name"), hit(10), energy(10), damage(0)
{
	std::cout << "ClapTrap default constructor call" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit(10), energy(10), damage(0)
{
	std::cout << "ClapTrap name constructor call" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	std::cout << "ClapTrap copy constructor call" << std::endl;
	*this = source;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor call" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &source)
{
	this->name = source.name;
	this->hit = source.hit;
	this->energy = source.energy;
	this->damage = source.damage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energy < 1 || this->hit < 1)
	{
		std::cout << this->name << " doesn't have enough energy points to attack." << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "ClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit < 1)
	{
		std::cout << this->name << " is already dead!" << std::endl;
		return ;
	}
	this->hit -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy < 1 || this->hit < 1)
	{
		std::cout << this->name << " doesn't have enough energy points to repair." << std::endl;
		return ;
	}
	this->hit += amount;
	this->energy--;
	std::cout << "ClapTrap " << this->name << " repairs itself, regaining " << amount;
	std::cout << " health points!" << std::endl;
}
