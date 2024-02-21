/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:33:37 by vegret            #+#    #+#             */
/*   Updated: 2024/02/21 15:15:31 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <stack>
# include <limits>
# include <iostream>
# include <stdexcept>

class RPN {
	private:
		RPN();
		RPN(const RPN& source);
		RPN& operator=(const RPN& source);

	public:
		~RPN();
		static int evaluate(std::string expr);
};

#endif