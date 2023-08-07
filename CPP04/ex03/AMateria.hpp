/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:16:50 by vegret            #+#    #+#             */
/*   Updated: 2023/07/05 16:35:14 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(const AMateria &source);
		AMateria(std::string const &type);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &source);
		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif