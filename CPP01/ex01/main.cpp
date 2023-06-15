/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:00:43 by vegret            #+#    #+#             */
/*   Updated: 2023/06/15 16:50:58 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int nb_zombies = 5;
	Zombie *horde = zombieHorde(nb_zombies, "Steve");

	if (!horde)
		return 1;

	for (int i = 0; i < nb_zombies; i++)
		horde[i].announce();
	
	delete [] horde;
	
	return 0;
}
