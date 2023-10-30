/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:48:04 by vegret            #+#    #+#             */
/*   Updated: 2023/10/27 01:56:02 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F fun) {
	for (size_t i = 0; i < length; i++) {
		fun(array[i]);
	}
}

template <typename T>
void print(T val) {
	std::cout << val << " ";
}

#endif