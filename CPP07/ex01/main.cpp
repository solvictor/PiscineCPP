/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:48:26 by vegret            #+#    #+#             */
/*   Updated: 2023/10/31 01:32:58 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main() {
	int arr1[] = {1, 2, 3, 4, 5};
	iter(arr1, 5, printer<int>);
	std::cout << std::endl;

	double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(arr2, 5, printer<double>);
	std::cout << std::endl;

	char arr3[] = {'a', 'b', 'c', 'd', 'e'};
	iter(arr3, 5, printer<char>);
	std::cout << std::endl;

	return 0;
}
