/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:33:43 by vegret            #+#    #+#             */
/*   Updated: 2024/02/21 15:15:36 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& source __attribute__((unused))) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& source __attribute__((unused))) {
	return *this;
}

// static void print_stack(std::stack<long> stack) {
// 	if (!stack.size()) {
// 		std::cout << "Empty stack" << std::endl;
// 		return;
// 	}

// 	while (stack.size()) {
// 		std::cout << stack.top() << " ";
// 		stack.pop();
// 	}
// 	std::cout << std::endl;
// }

int RPN::evaluate(std::string expr) {
	std::stack<long> stack;
	long tmp;

	for (size_t i = 0; i < expr.size(); i++) {
		if (isspace(expr[i]))
			continue;

		if (isdigit(expr[i])) {
			stack.push(expr[i] - '0');
			continue;
		}

		if (stack.size() < 2)
			throw std::runtime_error("Error: Bad format");

		tmp = stack.top();
		stack.pop();

		if (expr[i] == '+') {
			stack.top() += tmp;
		}
		else if (expr[i] == '-') {
			stack.top() -= tmp;
		}
		else if (expr[i] == '*') {
			stack.top() *= tmp;
		}
		else if (expr[i] == '/') {
			if (tmp == 0)
				throw std::runtime_error("Error: Division by 0");
			stack.top() /= tmp;
		}
		else
			throw std::runtime_error("Error: Invalid character");

		if (stack.top() < std::numeric_limits<int>::min() ||
			stack.top() > std::numeric_limits<int>::max())
			throw std::runtime_error("Error: Integer overflow");
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error: Bad format");

	return static_cast<int>(stack.top());
}
