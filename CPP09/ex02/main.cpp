/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:21 by vegret            #+#    #+#             */
/*   Updated: 2023/11/17 01:03:25 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>
#include <limits>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"

static size_t get_num(std::string str) {
	if (str.size() > 10)
		throw std::runtime_error("Error: " + str + " is not a valid positive integer");

	size_t i = 0;

	while (i < str.size()) {
		if (!std::isdigit(str[i]))
			throw std::runtime_error("Error: " + str + " is not a valid positive integer");
		i++;
	}

	long res = std::atol(str.c_str());

	if (res > std::numeric_limits<unsigned long>::max())
		throw std::runtime_error("Error: " + str + " is not a valid positive integer");

	return static_cast<int>(res);
}

static unsigned long long current_time_micros() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000UL + tv.tv_usec;
}

int main(int argc, char **argv) {

	if (argc == 1) {
		std::cout << "Usage: ./PmergeMe <space separated numbers>" << std::endl;
		return 1;
	}

	std::deque<int> deque;
	std::vector<int> vector;

	try {
		for (int i = 1 ; i < argc ; i++) {
			int parsed = get_num(argv[i]);

			deque.push_back(parsed);
			vector.push_back(parsed);
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < vector.size(); i++) {
		if (i)
			std::cout << " ";
		std::cout << vector[i];
	}
	std::cout << std::endl;

	unsigned long long start_vector = current_time_micros();
	PmergeMe::sort(vector);
	unsigned long long elapsed_vector = current_time_micros() - start_vector;

	unsigned long long start_deque = current_time_micros();
	PmergeMe::sort(deque);
	unsigned long long elapsed_deque = current_time_micros() - start_deque;

	std::cout << "After (vector): ";
	for (size_t i = 0; i < vector.size(); i++) {
		if (i)
			std::cout << " ";
		std::cout << vector[i];
	}
	std::cout << std::endl;

	std::cout << "After (deque):  ";
	for (size_t i = 0; i < deque.size(); i++) {
		if (i)
			std::cout << " ";
		std::cout << deque[i];
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : "
			<< std::fixed << std::setprecision(3) << elapsed_vector << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : "
			<< std::fixed << std::setprecision(3) << elapsed_deque << " us" << std::endl;

	return 0;
}
