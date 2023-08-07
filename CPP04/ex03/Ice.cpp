/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:56:17 by vegret            #+#    #+#             */
/*   Updated: 2023/07/05 16:51:29 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice &source)
{
	*this = source;
}

Ice &Ice::operator=(const Ice &source)
{
	if (&source == this)
		return (*this);
	this->type = source.type;
	return (*this);
}

Ice::~Ice() {}

Ice::Ice(const std::string &type)
{
	this->type = type;
}

Ice *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
