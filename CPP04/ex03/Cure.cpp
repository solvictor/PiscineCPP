/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:55:13 by vegret            #+#    #+#             */
/*   Updated: 2023/07/05 16:56:21 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure &source)
{
	*this = source;
}

Cure &Cure::operator=(const Cure &source)
{
	if (this == &source)
		return (*this);
	this->type = source.type;
	return (*this);
}

Cure::~Cure() {}

Cure::Cure(const std::string &type)
{
	this->type = type;
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}