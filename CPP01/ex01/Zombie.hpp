/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:59:45 by vegret            #+#    #+#             */
/*   Updated: 2023/06/27 13:18:56 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
	private:
		std::string nom;
	public:
		Zombie();
		Zombie(std::string nom);
		~Zombie();
		void announce(void);
		void setName(std::string name);
};

#endif