/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:33:43 by vegret            #+#    #+#             */
/*   Updated: 2023/11/27 18:34:31 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <limits>
#include <iostream>
#include <stdexcept>
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &source __attribute__((unused))) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &source __attribute__((unused))) {
	return *this;
}

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
	std::stack<long long> stack;
	long long a, b;

	for (size_t i = 0; i < expr.size(); i++) {
		if (std::isspace(expr[i]))
			continue;

		if (std::isdigit(expr[i])) {
			stack.push(expr[i] - '0');
			continue;
		}

		if (stack.size() < 2)
			throw std::runtime_error("Error");

		a = stack.top();
		stack.pop();
		b = stack.top();
		stack.pop();
		if (expr[i] == '+') {
			stack.push(a + b);
		}
		else if (expr[i] == '-') {
			stack.push(b - a);
		}
		else if (expr[i] == '*') {
			stack.push(a * b);
		}
		else if (expr[i] == '/') {
			if (a == 0)
				throw std::runtime_error("Error");
			stack.push(b / a);
		}
		else
			throw std::runtime_error("Error");

		if (stack.top() < std::numeric_limits<int>::min() ||
			stack.top() > std::numeric_limits<int>::max())
			throw std::runtime_error("Error");
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error");

	return stack.top();
}
