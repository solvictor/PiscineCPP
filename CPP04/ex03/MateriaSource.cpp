/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:59:06 by vegret            #+#    #+#             */
/*   Updated: 2023/09/18 14:53:30 by vegret           ###   ########.fr       */
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

void MateriaSource::learnMateria(AMateria* m)
{
	int items = 0;

	if (m == NULL)
	{
		std::cout << "Bad Materia!" << std::endl;
		return ;
	}
	while (this->materias[items] && items < MATERIAS_SIZE)
	{
		if (this->materias[items] == m) // If same instance
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
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	int i;

	for (i = MATERIAS_SIZE - 1; i >= 0; i--)
	{
		if (this->materias[i] && this->materias[i]->getType() == type)
			return (this->materias[i]->clone());
	}
	return (NULL);
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
