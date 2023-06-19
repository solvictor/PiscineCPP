/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:29:06 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 18:57:36 by vegret           ###   ########.fr       */
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
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongAnimal* meta2 = new WrongAnimal();
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl << std::endl;;

	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	wrongCat->makeSound();
	meta2->makeSound();

	delete wrongCat;
	delete meta2;
	delete meta;
	delete dog;
	delete cat;

	return 0;
}
