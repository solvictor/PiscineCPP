/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:39:49 by vegret            #+#    #+#             */
/*   Updated: 2023/10/24 17:42:54 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Fabrice", 1);
		std::cout << b1;
		b1.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b2;
		std::cout << b2;
		b2.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("Damien", 160);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("Emile", -5);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
