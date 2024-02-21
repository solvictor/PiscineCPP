/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:48:43 by vegret            #+#    #+#             */
/*   Updated: 2024/02/21 15:29:14 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {

	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		Exchanger exchanger;

		exchanger.load_data(const_cast<char*>("data.csv"));

		exchanger.display_data(static_cast<char*>(argv[1]));
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
