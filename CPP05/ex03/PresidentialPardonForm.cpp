/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:54:48 by vegret            #+#    #+#             */
/*   Updated: 2023/10/25 00:50:25 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", "Default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source)
	: AForm(source) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &source) {
	AForm::operator=(source);
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::checkRequirements(executor);

	std::cout << "Zaphod Beeblebrox pardoned " << _target << "." << std::endl;
}
