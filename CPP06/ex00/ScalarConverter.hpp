/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:34:06 by vegret            #+#    #+#             */
/*   Updated: 2023/10/25 21:29:38 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

typedef struct s_num {
	char c;
	bool isValidChar;
	int n;
	bool isValidInt;
	float f;
	bool isValidFloat;
	double d;
} t_num;

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &source);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &source);

		static void convert(const std::string input);
};

#endif