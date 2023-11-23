/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:43 by vegret            #+#    #+#             */
/*   Updated: 2023/11/20 18:11:25 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <deque>
# include <vector>
# include <stdlib.h>
# include <iostream>

class PmergeMe {
	private:
		template <typename T>
		static void sort_pairs(T& container) {
			for (size_t i = 0; i < container.size() - 1; i += 2)
				if (container[i] > container[i + 1])
					std::swap(container[i], container[i + 1]);
		}

		template <typename T>
		static void insertion(T& result, size_t element) {
			int left = 0;
			int right = result.size() - 1;
			int mid;

			while (left <= right) {
				mid = left + (right - left) / 2;
				if (element < result[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}

			result.insert(result.begin() + left, element);
		}

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &source);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &source);

		template <typename T>
		static void sort(T& container) {
			static int jacobsthal[] = {0, 2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730, 5460, 10922, 21844, 43690, 87380, 174762, 349524, 699050, 1398100, 2796202, 5592404, 11184810, 22369620, 44739242, 89478484, 178956970, 357913940, 715827882, 1431655764, 2147483647};

			sort_pairs(container);
			if (container.size() <= 2)
				return;
			T smallests;
			//T biggests;
			for (size_t i = 0; i < container.size(); i += 2) {
				smallests.push_back(container[i]);
				//if (i)
				//	biggests.push_back(container[i - 1]);
			}
			sort(smallests);
			T biggests;
			for (size_t i = 1; i < container.size(); i += 2)
				biggests.push_back(container[i]);
			for (size_t index = 0; index < biggests.size(); )
			{
				int jacobsthal_index = 0;
				while (static_cast<int>(index) < jacobsthal[jacobsthal_index])
					jacobsthal_index++;
				if (jacobsthal_index)
				{
					if (static_cast<int>(biggests.size() - 1) <= jacobsthal[jacobsthal_index])
						jacobsthal_index = biggests.size() - (index - jacobsthal[jacobsthal_index - 1]);
					else
						jacobsthal_index =  jacobsthal[jacobsthal_index] + 1 - (index - jacobsthal[jacobsthal_index - 1]);
				}
				insertion(smallests, biggests[jacobsthal_index]);
				biggests.erase(biggests.begin() + jacobsthal_index);
			}
			container = smallests;
		}
};

#endif