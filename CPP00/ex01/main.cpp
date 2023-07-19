/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:21:05 by vegret            #+#    #+#             */
/*   Updated: 2023/07/19 15:58:04 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include "PhoneBook.hpp"

bool	ask(std::string message, std::string& dst)
{
	if (!message.empty())
		std::cout << message << std::endl;
	if (!std::getline(std::cin, dst))
		return true;
	return false;
}

int	main(void)
{
	std::string command;
	PhoneBook book;

	do
	{
		if (ask("Available commands: ADD, SEARCH, EXIT.", command))
			break;
		if (command == "ADD")
		{
			std::string infos[5];
			if (ask("Enter first name:", infos[0]) ||
				ask("Enter last name:", infos[1]) ||
				ask("Enter nick name:", infos[2]) ||
				ask("Enter phone number:", infos[3]) ||
				ask("Enter secret:", infos[4]))
				break;
			book.add(infos);
		}
		else if (command == "SEARCH")
		{
			if (book.getNbContacts() == 0)
				std::cout << "PhoneBook is empty." << std::endl;
			else
			{
				book.displayContacts();
				std::string target;
				if (ask("Enter contact index.", target))
					break;
				long targetIndex = std::atol(target.c_str());
				if (target.length() > 10 || targetIndex < 1 || targetIndex > book.getNbContacts())
					std::cout << "Invalid index, index should be between 1 and " << book.getNbContacts() << " inclusive." << std::endl;
				else
					book.displayContact(targetIndex - 1);
			}
		}
	}
	while (command != "EXIT" && !std::cin.eof());
	return 0;
}
