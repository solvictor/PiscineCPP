/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:49:30 by vegret            #+#    #+#             */
/*   Updated: 2023/10/25 01:57:02 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &source);
		~Intern();
		Intern &operator=(const Intern &source);

		AForm* makeForm(std::string name, std::string target);

		class UnknownFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif