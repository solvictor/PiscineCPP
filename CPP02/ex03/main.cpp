/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:02:56 by vegret            #+#    #+#             */
/*   Updated: 2023/06/18 23:45:22 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(-1.8f, 0);
	Point b(0.5f, 0);
	Point c(1.5f, 2);
	
	Point d(1.2f, 1.42f);

	if (bsp(a, b, c, d))
		std::cout << "Le point est dans le triangle" << std::endl;
	else
		std::cout << "Le point n'est pas dans le triangle" << std::endl;

	return 0;
}
