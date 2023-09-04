/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:16:52 by vegret            #+#    #+#             */
/*   Updated: 2023/09/04 17:27:36 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria() : type("none"), _next(NULL) {}

AMateria::AMateria(const AMateria &source)
{
	*this = source;
}

AMateria::AMateria(std::string const &type) : type(type), _next(NULL) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &source)
{
	this->type = source.type;
	this->_next = source._next;
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
