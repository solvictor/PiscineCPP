/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:33:37 by vegret            #+#    #+#             */
/*   Updated: 2023/11/16 18:43:58 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <string>

class RPN {
	public:
		RPN();
		RPN(const RPN &source);
		~RPN();
		RPN &operator=(const RPN &source);
		static int evaluate(std::string expr);
};

#endif