/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:37:06 by vegret            #+#    #+#             */
/*   Updated: 2023/10/26 16:57:10 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

static void section(std::string title, std::string inputs[], size_t size) {
	std::cout << title << std::endl;
	std::cout << std::endl;

	for (size_t i = 0; i < size; i++) {
		std::cout << "Input: \"" << inputs[i] << '"' << std::endl;
		ScalarConverter::convert(inputs[i]);
		std::cout << std::endl;
	}
}

static void test() {
	std::string test_chars[] = {"' '", "'*'", "'0'", "'A'", "'z'", "'~'", "'è'"};
	section("CHARACTERS", test_chars, 7);

	std::string test_ints[] = {"-2147483649", "-2147483648", "-1", "0", "1", "42", "+2147483647", "2147483648"};
	section("INTEGERS", test_ints, 8);

	std::string test_floats[] = {"-340282346638528859811704183484516925440.0f", "-42.0f", "1.1f",
					   "0.000000000001f",
					   "99999999999999999999999999999999999999999999999999999999999999.0f"};
	section("FLOATS", test_floats, 5);

	std::string test_doubles[] = {"-340282346638528859811704183484516925440.0", "-42.0", "1.1",
					   "+0.000000000001",
					   "99999999999999999999999999999999999999999999999999999999999999.0"};
	section("DOUBLES", test_doubles, 5);

	std::string test_strings[] = {"inf", "-inf", "+inf", "nan", "inff", "-inff", "+inff", "nanf", "nope"};
	section("SPECIAL VALUES", test_strings, 9);
}

int main(int argc, char const *argv[]) {
	switch (argc) {
		case 1:
			test();
			break;

		case 2:
			ScalarConverter::convert(argv[1]);
			break;
		
		default:
			std::cout << "Usage: " << argv[0] << " (<char> | <int> | <float> | <double>)?" << std::endl;
			return 1;
	}
	return 0;
}
