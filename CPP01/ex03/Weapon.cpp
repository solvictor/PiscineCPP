/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:22:37 by vegret            #+#    #+#             */
/*   Updated: 2023/06/15 18:17:54 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon() : type("Undefined") {}

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType()
{
	return this->type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
