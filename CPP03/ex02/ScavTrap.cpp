/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:17:04 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 15:48:43 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = source;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &source)
{
	ClapTrap::operator=(source);
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energy < 1 || this->hit < 1)
	{
		std::cout << this->name << " doesn't have enough energy points to attack." << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "SlavTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " enters gate guardian mode!" << std::endl;
}
