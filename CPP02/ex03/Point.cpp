/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:40:46 by vegret            #+#    #+#             */
/*   Updated: 2023/08/06 17:57:50 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() {}

Point::Point(float x, float y) : x(x), y(y) {}

Point::Point(const Point &source) : x(source.x), y(source.y) {}

Point::~Point() {}

Point &Point::operator=(const Point &source)
{
	(void) source;
	return *this;
}

const Fixed &Point::getX() const
{
	return this->x;
}

const Fixed &Point::getY() const
{
	return this->y;
}

