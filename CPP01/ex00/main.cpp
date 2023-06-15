/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:00:43 by vegret            #+#    #+#             */
/*   Updated: 2023/06/15 16:24:58 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main()
{
	randomChump("Stack");

	Zombie *heap = newZombie("Heap");

	if (!heap)
		return 1;

	heap->announce();

	return 0;
}
