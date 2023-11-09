/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:49:16 by vegret            #+#    #+#             */
/*   Updated: 2023/11/09 18:56:08 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_TPP
# define MUTANSTACK_TPP
# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
	
};

#endif