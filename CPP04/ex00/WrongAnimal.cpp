/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:59:07 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 19:01:43 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source)
{
	std::cout << "WrongAnimal was created" << std::endl;
	*this = source;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal was created" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal was Destroyed" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &source)
{
	this->type = source.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Grgrgrgrggrgrrrrrrr" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
