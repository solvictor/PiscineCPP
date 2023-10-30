/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:33:50 by vegret            #+#    #+#             */
/*   Updated: 2023/10/27 01:37:48 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

template <typename T>
const T& min(const T& a, const T& b) {
	return a < b ? a : b;
}

template <typename T>
const T& max(const T& a, const T& b) {
	return a > b ? a : b;
}

#endif