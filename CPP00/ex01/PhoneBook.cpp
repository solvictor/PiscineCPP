/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:18:47 by vegret            #+#    #+#             */
/*   Updated: 2023/06/14 19:38:49 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->nbContacts = 0;
	this->placeIndex = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add(std::string *infos)
{
	Contact& target = this->contacts[this->placeIndex];
	target.setFirstName(infos[0]);
	target.setLastName(infos[1]);
	target.setNickName(infos[2]);
	target.setPhoneNumber(infos[3]);
	target.setSecret(infos[4]);
	if (this->nbContacts < CAPACITY)
		this->nbContacts++;
	this->placeIndex = (this->placeIndex + 1) % CAPACITY;
}

int		PhoneBook::getNbContacts()
{
	return this->nbContacts;
}

std::string	formatInfo(const std::string& info, size_t width)
{
	if (info.length() > width)
		return info.substr(0, width - 1) + '.';
	return info;
}


void	PhoneBook::displayContacts()
{
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	std::cout << "──────────┼──────────┼──────────┼──────────" << std::endl;

	for (int i = 0; i < this->nbContacts; i++)
	{	
		std::cout.width(10);
		std::cout << std::right << i + 1 << '|';
		std::cout.width(10);
		std::cout << std::right << formatInfo(this->contacts[i].getFirstName(), 10) << '|';
		std::cout.width(10);
		std::cout << std::right << formatInfo(this->contacts[i].getLastName(), 10) << '|';
		std::cout.width(10);
		std::cout << std::right << formatInfo(this->contacts[i].getNickName(), 10) << std::endl;
	}
}

void	PhoneBook::displayContact(int i)
{
	Contact& target = this->contacts[i];
	std::cout << "First name: " << target.getFirstName() << std::endl;
	std::cout << "Last name: " << target.getLastName() << std::endl;
	std::cout << "Nick name: " << target.getNickName() << std::endl;
	std::cout << "Phone number: " << target.getPhoneNumber() << std::endl;
	std::cout << "Secret: " << target.getSecret() << std::endl;
}
