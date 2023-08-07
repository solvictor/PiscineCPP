/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:16:52 by vegret            #+#    #+#             */
/*   Updated: 2023/07/05 16:38:40 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria() : type("none") {}

AMateria::AMateria(const AMateria &source)
{
	*this = source;
}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &source)
{
	if (&source == this)
		return *this;
	this->type = source.type;
	return *this;
}

const std::string &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << this->type << " is being thrown at " << target.getName() << std::endl;
}
