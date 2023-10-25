/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:39:49 by vegret            #+#    #+#             */
/*   Updated: 2023/10/25 02:33:53 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat samuel("Samuel", 1);
	Intern vincent;
	AForm* form;

	form = vincent.makeForm("robotomy request", "Bender");
	form->beSigned(samuel);
	form->execute(samuel);
	delete form;

	try {
		form = vincent.makeForm("burger king", "Steve");
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
