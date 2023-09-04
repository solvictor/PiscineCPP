/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:33:43 by vegret            #+#    #+#             */
/*   Updated: 2023/09/04 16:27:32 by vegret           ###   ########.fr       */
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
	*this = source;
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
	delete this->brain;
	this->brain = new Brain(*source.brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "bark" << std::endl;
}
