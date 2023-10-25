/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:18:53 by vegret            #+#    #+#             */
/*   Updated: 2023/10/25 02:30:34 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "Default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source)
	: AForm(source) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source) {
	AForm::operator=(source);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	AForm::checkRequirements(executor);

	std::cout << "BRRRRRR....KKRKRRKRKKRKRKRRRKR" << std::endl;
	
	srand(time(NULL));
	bool success = rand() & 1;
	
	std::cout << "Robotomy of " << _target << (success ? " was a success" : " has failed") << "." << std::endl;
}
