/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:39:49 by vegret            #+#    #+#             */
/*   Updated: 2023/10/23 23:06:24 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat eric("Eric", 1);
	Bureaucrat homer("Homer", 42);
	Bureaucrat franklin("Franklin", 150);

	Form goToRestaurant("GoToRestaurant", 1, 1);
	Form playPingPong("PlayPingPong", 140, 140);

	try {
		Form gerard("Gerard", 0, 30);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	eric.signForm(goToRestaurant);
	homer.signForm(goToRestaurant);
	franklin.signForm(goToRestaurant);
	franklin.signForm(playPingPong);

	std::cout << std::endl;

	goToRestaurant.beSigned(eric);
	playPingPong.beSigned(eric);
	
	try {
		goToRestaurant.beSigned(homer);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	playPingPong.beSigned(homer);

	try {
		goToRestaurant.beSigned(franklin);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		playPingPong.beSigned(franklin);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
