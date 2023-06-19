/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:15:53 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 16:22:52 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap string constructor called" << std::endl;
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = source;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &source)
{
	ClapTrap::operator=(source);
	return *this;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " want to high fives!" << std::endl;
}
