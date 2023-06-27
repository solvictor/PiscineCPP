/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:01:10 by vegret            #+#    #+#             */
/*   Updated: 2023/06/27 13:19:18 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
		return (NULL);

	Zombie *horde = new Zombie[N];

	if (!horde)
		return (NULL);

	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return horde;
}