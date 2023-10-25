/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:37:27 by vegret            #+#    #+#             */
/*   Updated: 2023/10/24 17:56:05 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat& operator=(const Bureaucrat& bureaucrat);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void signForm(AForm& form);
		void executeForm(AForm const & form);

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		static const int highestGrade = 1;
		static const int lowestGrade = 150;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif