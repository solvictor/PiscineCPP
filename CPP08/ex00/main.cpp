/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:33:46 by vegret            #+#    #+#             */
/*   Updated: 2023/10/27 19:27:21 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int>	vector;
	std::list<int>		list;

	std::srand(time(NULL));
	
	for (int i = 0; i < 10; i++) {
		vector.push_back(std::rand() % 15);
		list.push_back(std::rand() % 15);
	}

	std::cout << "Vector content:" << std::endl;
	display_container(vector);
	std::cout << "List content:" << std::endl;
	display_container(list);

	try {
		std::cout << "Trying to find 3 in vector:" << std::endl;
		std::cout << *easyfind(vector, 3) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to find 3 in list:" << std::endl;
		std::cout << *easyfind(list, 3) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to find 150 in vector:" << std::endl;
		std::cout << *easyfind(vector, 150) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to find 150 in list:" << std::endl;
		std::cout << *easyfind(list, 150) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
