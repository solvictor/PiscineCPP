/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:29:06 by vegret            #+#    #+#             */
/*   Updated: 2023/09/04 15:39:25 by vegret           ###   ########.fr       */
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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "Wrong Part" << std::endl << std::endl ;

	// Wrong implementation
	const WrongAnimal* bad = new WrongAnimal();
	const WrongAnimal* anicat = new WrongCat();

	std::cout << anicat->getType() << " " << std::endl;

	anicat->makeSound(); // will output the animal sound!
	bad->makeSound();

	delete bad;
	delete anicat;

	return 0;
}
