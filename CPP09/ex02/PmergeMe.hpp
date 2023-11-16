/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:43 by vegret            #+#    #+#             */
/*   Updated: 2023/11/16 15:12:24 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &source);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &source);
};

#endif