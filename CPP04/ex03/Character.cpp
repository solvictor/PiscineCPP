/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:47:24 by vegret            #+#    #+#             */
/*   Updated: 2023/07/05 17:34:19 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

Character::Character()
{
	this->name = "default";
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->inventory[i] = NULL;
	this->trash = NULL;
}

Character::Character(const Character &source)
{
	*this = source;
}

Character &Character::operator=(const Character &source)
{
	if (this == &source)
		return (*this);
	this->name = source.name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		if (source.inventory[i] != NULL)
			this->inventory[i] = source.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	this->trash = NULL;
	return (*this);
}

Character::~Character()
{
	AMateria *tmp_trash;

	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->inventory[i] != NULL)
			delete inventory[i];
	}
	
	while (this->trash != NULL)
	{
		tmp_trash = this->trash;
		trash = trash->_next;
		if (tmp_trash)
			delete tmp_trash;
	}
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->inventory[i] = NULL;
	this->trash = NULL;
}

const std::string &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	int first_free = -1;

	if (m == NULL)
	{
		std::cout << "Invalid materia!" << std::endl;
		return ;
	}
	if (count_items() == INVENTORY_SIZE)
	{
		std::cout << "Inventory is already full! Can't equip " << m->getType() << "!" << std::endl;
		push_trash(-1, m);
		return ;
	}
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->inventory[i] == NULL && first_free == -1)
			first_free = i;
		if (this->inventory[i] == m)
		{
			std::cout << "Item " << m->getType() <<" is already equiped!" << std::endl;
			return ;
		}	
	}
	this->inventory[first_free] = m;
	std::cout << "Equiped " << m->getType() << " in slot " << first_free << std::endl;
}

void Character::unequip(int i) 
{
	if (check_slot(i) == false)
		return ;
	std::cout << "Unequiped " << this->inventory[i]->getType()
			<< ", previously stored in slot " << i << std::endl;
	push_trash(i, this->inventory[i]);
}

void Character::use(int i, ICharacter &target)
{
	if (check_slot(i) == false)
		return ;
	if (this->inventory[i] == NULL)
	{
		std::cout << "The slot " << i << " is empty! " << this->name
			<< " can't do anything!" << std::endl;
		return ;
	}
	std::cout << "Using " << this->inventory[i]->getType()
		<< " stored in slot " << i << "!" << std::endl;
	this->inventory[i]->use(target);
	push_trash(i, this->inventory[i]);
}

bool Character::check_slot(int i)
{
	if (i < 0 || i >= INVENTORY_SIZE)
	{
		std::cout << i << " isn't a correct inventory slot!" << std::endl;
		return (false);
	}
	if (this->inventory[i] == NULL)
	{
		std::cout << i << " is empty!" << std::endl;
		return (false);
	}
	return (true);
}

int Character::count_items()
{
	int items = 0;

	for (int i = 0; i < INVENTORY_SIZE; i++)
		items += this->inventory[i] != NULL;
	return (items);
}

void Character::push_trash(int i, AMateria *to_trash)
{
	AMateria *tmp_trash;
	
	tmp_trash = this->trash;
	this->trash = to_trash;
	if (to_trash) //Impossible but protection is good 
		to_trash->_next = tmp_trash;
	if (i != -1)
		this->inventory[i] = NULL;
}

void Character::empty_inventory()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->unequip(i);
}

void Character::display_inventory()
{
	std::cout << "===============================================" << std::endl;
	std::cout << "Inventory of " << this->name << ":" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->inventory[i] == NULL)
			std::cout << i << ". Empty" << std::endl;
		else
			std::cout << i << ". " << this->inventory[i]->getType() << std::endl;
	}
	std::cout << "===============================================" << std::endl;
}

void Character::display_trash()
{
	AMateria *tmp = this->trash;
	int i = 0;
	
	std::cout << "***********************************************" << std::endl;
	std::cout << "Trash of " << this->name << ":" << std::endl;
	while (tmp)
	{
		std::cout << i++ << ". " << tmp->getType() << std::endl;
		tmp = tmp->_next;
	}
	std::cout << "***********************************************" << std::endl;
}
