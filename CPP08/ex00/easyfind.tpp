/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:35:21 by vegret            #+#    #+#             */
/*   Updated: 2023/10/27 18:51:13 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
typename T::iterator easyfind(const T& container, int target) {
	typename T::iterator result = std::find(container.begin(), container.end(), target);

	if (result == container.end())
		throw std::out_of_range("Value not found in container");
	return result;
}

#endif