/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:27:35 by vegret            #+#    #+#             */
/*   Updated: 2023/06/27 14:45:36 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat was created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal(source.type)
{
	std::cout << "WrongCat was created" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat was destroyed" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &source)
{
	this->type = source.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
