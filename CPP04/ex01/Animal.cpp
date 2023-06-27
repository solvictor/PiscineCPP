/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:41:28 by vegret            #+#    #+#             */
/*   Updated: 2023/06/27 14:46:20 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal was created" << std::endl;
}

Animal::Animal(const Animal &source)
{
	std::cout << "Animal was created" << std::endl;
	*this = source;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal was created" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal was Destroyed" << std::endl;
}

Animal &Animal::operator=(const Animal &source)
{
	this->type = source.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "undefined" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
