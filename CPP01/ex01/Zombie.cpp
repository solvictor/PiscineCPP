/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:00:12 by vegret            #+#    #+#             */
/*   Updated: 2023/06/27 13:18:09 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string nom) : nom(nom) {}

Zombie::~Zombie()
{
	std::cout << this->nom << " est mort (vraiment cette fois)" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->nom << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->nom = name;
}
