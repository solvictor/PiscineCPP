/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:04:09 by vegret            #+#    #+#             */
/*   Updated: 2023/06/19 19:01:54 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &source);
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &source);
		void makeSound() const;
		std::string getType() const;	
};
#endif
