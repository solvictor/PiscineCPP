/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:41:28 by vegret            #+#    #+#             */
/*   Updated: 2023/09/04 16:39:58 by vegret           ###   ########.fr       */
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

std::string Animal::getType() const
{
	return this->type;
}
