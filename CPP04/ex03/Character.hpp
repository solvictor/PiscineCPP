/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:47:20 by vegret            #+#    #+#             */
/*   Updated: 2023/09/18 14:38:48 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# define INVENTORY_SIZE 4
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[INVENTORY_SIZE];
		AMateria *trash;
		void push_trash(int i, AMateria *to_trash);
		bool check_slot(int i);
		int count_items();
	public:
		Character();
		Character(std::string name);
		Character(const Character &source);
		~Character();
		Character &operator=(const Character &source);
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int i);
		void use(int i, ICharacter &target);
		void display_trash();
		void display_inventory();
		void empty_inventory();
};

#endif