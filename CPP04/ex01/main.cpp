/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:29:06 by vegret            #+#    #+#             */
/*   Updated: 2023/06/27 14:52:51 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal tab[10];
	
	for (int i = 0 ; i < 10 ; i++)
	{
		if (i < 5)
			tab[i] = Dog();
		else
			tab[i] = Cat();
	}
	// TODO Finir
	return 0;
}
