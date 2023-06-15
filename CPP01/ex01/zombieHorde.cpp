/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:01:10 by vegret            #+#    #+#             */
/*   Updated: 2023/06/15 17:36:36 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];

	if (!horde)
		return (nullptr);

	for (int i = 0; i < N; i++)
		horde[i] = Zombie(name); // Fix deleting zombies previously allocated

	return horde;
}