/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:33:43 by vegret            #+#    #+#             */
/*   Updated: 2023/11/16 14:54:57 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include <stdexcept>
#include "RPN.hpp"

RPN::RPN() {}

//static void print_stack(std::stack<int> stack) {
//	if (!stack.size()) {
//		std::cout << "Empty stack" << std::endl;
//		return;
//	}
//
//	while (stack.size()) {
//		std::cout << stack.top() << " ";
//		stack.pop();
//	}
//	std::cout << std::endl;
//}

int RPN::evaluate(std::string expr) {
	std::stack<int> stack;
	int a, b;

	for (size_t i = 0; i < expr.size(); i++) {
		if (std::isspace(expr[i]))
			continue;

		if (std::isdigit(expr[i]))
			stack.push(expr[i] - '0');
		else if (stack.size() < 2)
			throw std::runtime_error("Error");
		else if (expr[i] == '+') {
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			stack.push(a + b);
		}
		else if (expr[i] == '-') {
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			stack.push(b - a);
		}
		else if (expr[i] == '*') {
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop(); 
			stack.push(a * b);
		}
		else if (expr[i] == '/') {
			a = stack.top();
			if (a == 0)
				throw std::runtime_error("Error");
			stack.pop();
			b = stack.top();
			stack.pop();
			stack.push(b / a);
		}
		else
			throw std::runtime_error("Error");
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error");

	return stack.top();
}
