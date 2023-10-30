/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:33:23 by vegret            #+#    #+#             */
/*   Updated: 2023/10/27 01:47:12 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

static void test_subject() {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

static void test_swap() {
	std::cout << "Test for swap function" << std::endl;

	int a = -1, b = 42;
	swap(a, b);

	std::cout << "a: " << a << ", b: " << b << std::endl;

	double c = 3.1415, d = 2.7182;
	swap(c, d);

	std::cout << "c: " << c << ", d: " << d << std::endl;

	char e = 'E', f = 'F';
	swap(e, f);

	std::cout << "e: " << e << ", f: " << f << std::endl;

	std::cout << std::endl;
}

static void test_min() {
	std::cout << "Test for min function" << std::endl;

	int a = -1, b = 42;

	std::cout << "min(" << a << ", " << b << ") = " << min(a, b) << std::endl;

	double c = 3.1415, d = 2.7182;

	std::cout << "min(" << c << ", " << d << ") = " << min(c, d) << std::endl;

	char e = 'E', f = 'F';

	std::cout << "min(" << e << ", " << f << ") = " << min(e, f) << std::endl;

	std::cout << std::endl;
}

static void test_max() {
	std::cout << "Test for max function" << std::endl;

	int a = -1, b = 42;

	std::cout << "max(" << a << ", " << b << ") = " << max(a, b) << std::endl;

	double c = 3.1415, d = 2.7182;

	std::cout << "max(" << c << ", " << d << ") = " << max(c, d) << std::endl;

	char e = 'E', f = 'F';

	std::cout << "max(" << e << ", " << f << ") = " << max(e, f) << std::endl;

	std::cout << std::endl;
}

int main() {
	test_subject();

	std::cout << std::endl;

	test_swap();

	test_min();

	test_max();

	return 0;
}
