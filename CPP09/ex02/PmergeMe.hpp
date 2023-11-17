/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:43 by vegret            #+#    #+#             */
/*   Updated: 2023/11/17 00:27:37 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <deque>
# include <vector>
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
			static const size_t jacobsthal[] = {2u,
											 2u,
											 6u,
											 10u,
											 22u,
											 42u,
											 86u,
											 170u,
											 342u,
											 682u,
											 1366u,
											 2730u,
											 5462u,
											 10922u,
											 21846u,
											 43690u,
											 87382u,
											 174762u,
											 349526u,
											 699050u,
											 1398102u,
											 2796202u,
											 5592406u,
											 11184810u,
											 22369622u,
											 44739242u,
											 89478486u,
											 178956970u,
											 357913942u,
											 715827882u,
											 1431655766u,
											 2863311530u,
											 5726623062u,
											 11453246122u,
											 22906492246u,
											 45812984490u,
											 91625968982u,
											 183251937962u,
											 366503875926u,
											 733007751850u,
											 1466015503702u,
											 2932031007402u,
											 5864062014806u,
											 11728124029610u,
											 23456248059222u,
											 46912496118442u,
											 93824992236886u,
											 187649984473770u,
											 375299968947542u,
											 750599937895082u,
											 1501199875790165u,
											 3002399751580331u,
											 6004799503160661u,
											 12009599006321322u,
											 24019198012642644u,
											 48038396025285288u,
											 96076792050570576u,
											 192153584101141152u,
											 384307168202282304u,
											 768614336404564608u,
											 1537228672809129216u,
											 3074457345618258432u,
											 6148914691236516864u};
		//	static int jacobsthal[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        //2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        //1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        //178956970, 357913942, 715827882, 1431655766};

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
			for (size_t index = 0; index < biggests.size(); ) {
				int jacobsthal_index = 0;
				while (index < jacobsthal[jacobsthal_index])
					jacobsthal_index++;
				if (jacobsthal_index) {
					if (biggests.size() - 1 <= jacobsthal[jacobsthal_index])
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