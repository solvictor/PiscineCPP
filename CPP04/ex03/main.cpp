/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:15:56 by vegret            #+#    #+#             */
/*   Updated: 2023/09/18 15:02:06 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	/*
		MY TESTS
	*/
	std::cout << "-------------------------TEST 1-------------------------" << std::endl;

	Cure*			cure_1;
	Ice*			ice_1;
	Cure*			cure_2;
	Ice*			ice_2;
	Cure*			cure_3;
	Character	 	player_1("Bob");

	cure_1 = new Cure("Cure 1");
	ice_1 = new Ice("Ice 1");
	cure_2 = new Cure("Cure 2");
	ice_2 = new Ice("Ice 2");
	cure_3 = new Cure("Cure 3");

	player_1.equip(cure_1);
	player_1.equip(ice_1);
	player_1.equip(cure_2);
	player_1.equip(ice_2);
	player_1.equip(cure_3);
	player_1.display_inventory();
	player_1.unequip(4);
	player_1.unequip(-1);
	player_1.unequip(100000000);
	player_1.equip(NULL);
	player_1.display_inventory();
	player_1.display_trash();
	player_1.empty_inventory();
	player_1.display_inventory();
	player_1.display_trash();

	std::cout << "-------------------------TEST 2-------------------------" << std::endl;
	Character		player_2("Jack");
	Cure*			cure_4;
	Ice*			ice_4;
	Cure*			cure_5;
	Ice*			ice_5;

	cure_4 = new Cure("Cure 4");
	ice_4 = new Ice("Ice 4");
	cure_5 = new Cure("Cure 5");
	ice_5 = new Ice("Ice 5");

	player_1.equip(cure_4);
	player_1.equip(ice_4);
	player_2.equip(cure_5);
	player_2.equip(ice_5);
	player_1.use(1, player_2);
	player_1.use(3, player_2);
	player_1.display_inventory();
	player_1.display_trash();
	player_2.unequip(1);

	std::cout << "-------------------------TEST 3-------------------------" << std::endl;
	
	Character		player_3(player_1);
	Cure*			cure_tmp;

	cure_tmp = new Cure(*cure_5);
	player_3.display_inventory();
	player_3.display_trash();
	player_3.equip(cure_tmp);
	player_3.display_inventory();
	
	std::cout << "-------------------------TEST 4-------------------------" << std::endl;
	std::cout << "Original Content (player 2):" << std::endl;
	player_2.display_inventory();
	player_2.display_trash();

	Character		player_4 = player_2;
	Cure*			cure_op;

	cure_op = cure_1->clone();
	player_4.display_inventory();
	player_4.display_trash();
	player_4.equip(cure_op);
	player_4.display_inventory();
	player_4.use(1, player_3);
	player_4.display_inventory();
	player_4.display_trash();

	std::cout << "-------------------------TEST 5-------------------------" << std::endl;
	MateriaSource	materia_source_1 = MateriaSource();
	MateriaSource	materia_source_2;
	Character		player_5;
	Cure*			cure_mat_source;

	cure_mat_source = new Cure("Prems");

	materia_source_1.learnMateria(cure_mat_source);
	materia_source_1.display_materias();
	AMateria* cure_materias;
	cure_materias = materia_source_1.createMateria("Cure Materia");
	player_5.equip(cure_materias);
	player_5.display_inventory();
	
	materia_source_2 = materia_source_1;
	materia_source_2.display_materias();

	delete cure_mat_source;
	
	std::cout << "----------------------SUBJECT TEST----------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	Ice *learn1 = new Ice();
	Cure *learn2 = new Cure();
	
	src->learnMateria(learn1);
	src->learnMateria(learn2);

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	delete learn1;
	delete learn2;
	
	return 0;
}
