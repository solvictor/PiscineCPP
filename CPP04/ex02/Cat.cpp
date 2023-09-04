/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:49:28 by vegret            #+#    #+#             */
/*   Updated: 2023/09/04 16:27:41 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat was created" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &source) : Animal(source.type)
{
	*this = source;
	std::cout << "Cat was created" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat was destroyed" << std::endl;
}

Cat &Cat::operator=(const Cat &source)
{
	this->type = source.type;
	delete this->brain;
	this->brain = new Brain(*source.brain);
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
