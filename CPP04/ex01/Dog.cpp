/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:33:43 by vegret            #+#    #+#             */
/*   Updated: 2023/06/27 14:45:22 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Dog was Created" << std::endl;
}

Dog::Dog(const Dog &source) : Animal(source.type)
{
	std::cout << "Dog was Created" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog was Destroyed" << std::endl;
}

Dog &Dog::operator=(const Dog &source)
{
	this->type = source.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "bark" << std::endl;
}
