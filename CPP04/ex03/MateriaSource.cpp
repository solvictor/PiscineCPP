/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:59:06 by vegret            #+#    #+#             */
/*   Updated: 2023/07/05 17:10:57 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MATERIAS_SIZE; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
	for (int i = 0; i < MATERIAS_SIZE; i++)
	{
		if (source.materias[i])
			this->materias[i] = source.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source)
{
	if (this == &source)
		return (*this);
	for (int i = 0; i < MATERIAS_SIZE; i++)
	{
		if (source.materias[i])
			this->materias[i] = source.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MATERIAS_SIZE; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
	}
}

/*
	"They are not necessarily unique." --> materias can have 2 cures, 2 ices...
	but the Materias need to be distinct instances.
	Thus, materias will never contains twice the same memory address (pointer
	to a given instance).
*/
void MateriaSource::learnMateria(AMateria* m)
{
	int items = 0;

	if (m == NULL)
	{
		std::cout << "Bad Materia!" << std::endl;
		return ;
	}
	while (this->materias[items] != NULL && items < MATERIAS_SIZE)
	{
		if (this->materias[items] == m)
		{
			std::cout << "Already have the EXACT same Materia in Materias!" << std::endl;
			return ;
		}
		items++;
	}	
	if (items == MATERIAS_SIZE)
	{
		std::cout << "Not enough space to store a new Materia!" << std::endl;
		return ;
	}
	this->materias[items] = m->clone();
	delete m;
}

bool	MateriaSource::is_in_materias(const std::string &type)
{
	for (int i = 0; i < MATERIAS_SIZE; i++)
	{
		if (this->materias[i] && this->materias[i]->getType() == type)
			return (true);
	}
	return (false);
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	int i;
	
	if (!this->is_in_materias(type))
		return (NULL);
	for (i = 0; i < MATERIAS_SIZE; i++)
	{
		if (this->materias[i] && this->materias[i]->getType() == type)
			break;
	}
	return (this->materias[i]->clone());
}

void MateriaSource::display_materias()
{
	std::cout << "###############################################" << std::endl;
	std::cout << "Content of Materias:" << std::endl;
	for (int i = 0; i < MATERIAS_SIZE; i++)
	{
		if (this->materias[i])
			std::cout << i << ". " << this->materias[i]->getType() << std::endl;
		else
			std::cout << i << ". Empty" << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}
