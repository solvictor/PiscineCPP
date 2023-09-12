/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:59:09 by vegret            #+#    #+#             */
/*   Updated: 2023/09/12 16:28:02 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# define MATERIAS_SIZE 4
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materias[MATERIAS_SIZE];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &source);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &source);
		void learnMateria(AMateria* m);
 		AMateria *createMateria(std::string const &type);
		void display_materias();
};

#endif