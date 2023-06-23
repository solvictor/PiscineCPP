/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:16:28 by vegret            #+#    #+#             */
/*   Updated: 2023/06/23 15:12:01 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define CAPACITY 8
# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
	private:
		int	nbContacts;
		int	placeIndex;
		Contact contacts[CAPACITY];
	public:
		PhoneBook();
		~PhoneBook();
		void add(std::string *infos);
		void displayContacts();
		void displayContact(int i);
		int getNbContacts();
};

#endif