/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:40:33 by vegret            #+#    #+#             */
/*   Updated: 2023/06/18 23:36:55 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

static Fixed sign(Point a, Point b, Point point)
{
	return (a.getX() - point.getX()) * (b.getY() - point.getY()) - (b.getX() - point.getX()) * (a.getY() - point.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = sign(a, b, point);
	Fixed d2 = sign(b, c, point);
	Fixed d3 = sign(c, a, point);

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	if (has_neg && has_pos)
		return false;

	bool on_edge = (d1 == 0) || (d2 == 0) || (d3 == 0);

	if (on_edge)
		return false;

	return true;
}
