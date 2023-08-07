/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:05:19 by vegret            #+#    #+#             */
/*   Updated: 2023/06/27 14:50:07 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain was created" << std::endl;
}

Brain::Brain(const Brain &source)
{
	*this = source;
}

Brain::~Brain()
{
	std::cout << "Brain was destroyed" << std::endl;
}

Brain &Brain::operator=(const Brain &source)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = source.ideas[i];

	return *this;
}
