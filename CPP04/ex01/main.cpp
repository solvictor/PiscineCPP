/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:29:06 by vegret            #+#    #+#             */
/*   Updated: 2023/09/04 16:14:33 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#define NB_ANIMALS 10

int main()
{
	Animal *tab[NB_ANIMALS];
	
	for (int i = 0 ; i < NB_ANIMALS ; i++)
	{
		if (i < NB_ANIMALS / 2)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
	}

	for (int i = 0 ; i < NB_ANIMALS ; i++)
		std::cout << "Animal " << i << " type: " << tab[i]->getType() << std::endl;

	for (int i = 0 ; i < NB_ANIMALS ; i++)
		delete tab[i];

	return 0;
}
