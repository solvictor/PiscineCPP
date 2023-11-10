/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:35:21 by vegret            #+#    #+#             */
/*   Updated: 2023/11/10 16:12:06 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP
# include <iterator>

template <class T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator result = std::find(container.begin(), container.end(), value);

	if (result == container.end())	
		throw std::runtime_error("Value not found in the container!");

	return result;
}

#endif