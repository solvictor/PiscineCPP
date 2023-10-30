/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:34:08 by vegret            #+#    #+#             */
/*   Updated: 2023/10/26 22:52:40 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &source) {
	(void) source;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source) {
	(void) source;
	return *this;
}

static bool isPrintable(char c) { return c >= ' ' && c <= '~'; }

static bool isSpecialDouble(const std::string& input) {
	return input == "inf" || input == "-inf" || input == "+inf" || input == "nan";
}

static bool isSpecial(const std::string& input) {
	return isSpecialDouble(input) || input == "inff" || input == "-inff" || input == "+inff" || input == "nanf";
}

static bool isChar(const std::string& input) {
	return input.size() == 3 && input[0] == '\'' && isPrintable(input[1]) && input[2] == '\'';
}

static bool convertNum(const std::string& input, t_num* num) {
	// TODO ignore more stuff like "+" "+." "f" and more
	if (input == "." || input == ".f" || input == "-." || input == "-.f")
		return false;
	int sign = 1;
	bool dotFound = false;
	double decimal = 0.1;
	num->d = 0;
	for (size_t i = 0; i < input.size(); i++) {
		char c = input[i];
		if (c == '.') {
			if (dotFound)
				return false;
			dotFound = true;
		} else if (c == '-') {
			if (i == 0)
				sign = -1;
			else
				return false;
		} else if (c == '+') {
			if (i != 0)
				return false;
		} else if (c == 'f') {
			if (i == input.size() - 1)
				num->d = static_cast<float>(num->d);
			else
				return false;
		} else if (isdigit(c)) {
			int digit = c - '0';
			if (dotFound) {
				num->d += decimal * digit;
				decimal *= 0.1;
			} else
				num->d = 10 * num->d + digit;
		} else
			return false;
	}
	num->d *= sign;
	if (!std::isfinite(num->d))
		return false;
	if (num->d >= std::numeric_limits<int>::min() &&
		num->d <= std::numeric_limits<int>::max() &&
		fmod(num->d, 1) == 0) {
		num->isValidInt = true;
		num->n = static_cast<int>(num->d);
		if (isPrintable(num->n)) {
			num->isValidChar = true;
			num->c = static_cast<char>(num->n);
		} else
			num->isValidChar = false;
	} else {
		num->isValidChar = num->isValidInt = false;
	}
	if (num->d >= -std::numeric_limits<float>::max() &&
		num->d <= std::numeric_limits<float>::max()) {
		num->f = static_cast<float>(num->d);
		num->isValidFloat = true;
	} else
		num->isValidFloat = false;
	return true;
}

static std::string formatDouble(double d) {
	std::stringstream ss;
	ss << std::fixed << std::setprecision(999) << d;
	std::string str = ss.str();
	if (str.find('.') != std::string::npos) {
		str = str.substr(0, str.find_last_not_of('0') + 1);
		if (str.find('.') == str.size() - 1)
			str += '0';
	}
	return str;
}

// TODO Revoir et essayer sans t_num
void ScalarConverter::convert(const std::string input) {
	t_num num;

	if (isSpecial(input)) {
		std::cout << "char  : impossible" << std::endl;
		std::cout << "int   : impossible" << std::endl;
		std::cout << "float : " << input + (isSpecialDouble(input) ? "f" : "") << std::endl;
		std::cout << "double: " << input << std::endl;
	} else if (isChar(input)) {
		std::cout << "char  : " << input[1] << std::endl;
		std::cout << "int   : " << static_cast<int>(input[1]) << std::endl;
		std::cout << "float : " << static_cast<float>(input[1]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[1]) << ".0" << std::endl;
	} else if (convertNum(input, &num)) {
		if (num.isValidChar)
			std::cout << "char : " << num.c << std::endl;
		else
			std::cout << "char  : Unavailable" << std::endl;
		if (num.isValidInt)
			std::cout << "int   : " << num.n << std::endl;
		else
			std::cout << "int   : Unavailable" << std::endl;
		if (num.isValidFloat)
			std::cout << "float : " << formatDouble(num.f) << 'f' << std::endl;
		else
			std::cout << "float : Unavailable" << std::endl;
		std::cout << "double: " << formatDouble(num.d) << std::endl;
	} else {
		std::cout << "Invalid input" << std::endl;
	}
}
