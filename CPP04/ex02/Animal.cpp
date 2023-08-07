/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:41:28 by vegret            #+#    #+#             */
/*   Updated: 2023/07/05 01:15:19 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal was created" << std::endl;
	return;
}

Animal::Animal(const Animal &source)
{
	std::cout << "Animal was created" << std::endl;
	*this = source;
	return;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal was created" << std::endl;
	return;
}

Animal::~Animal()
{
	std::cout << "Animal was Destroyed" << std::endl;
	return;
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
