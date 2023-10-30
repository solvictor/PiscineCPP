/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vegret <victor.egret.pro@gmail.com>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/27 02:14:58 by vegret			#+#	#+#			 */
/*   Updated: 2023/10/27 02:18:07 by vegret		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
	try {
		std::cout << "Empty Array tests" << std::endl;

		Array<int> empty_array;
		std::cout << "Empty: " << empty_array << std::endl;

		Array<int> copy_empty(empty_array);
		std::cout << "Copy of empty: " << copy_empty << std::endl;

		Array<int> array(10);
		for (uint i = 0; i < array.size(); i++)
			array[i] = i;

		std::cout << "Basic array: " << array << std::endl;

		Array<int> copy(array);
		std::cout << "Copy of basic: " << copy << std::endl;

		const Array<int> equal = copy;
		std::cout << "Equal operator test: " << equal << std::endl;
		
		Array<std::string> alphabet(26);
		for (uint i = 0; i < alphabet.size(); i++)
			alphabet[i] = 'a' + i;

		std::cout << "Alphabet: " << alphabet << std::endl;

		std::cout << "Going out of range:" << std::endl;
		std::cout << alphabet[alphabet.size()] << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		const Array<int> const_array(10);

		std::cout << "Const array: " << const_array << std::endl;

		std::cout << "Going out of range " << std::endl;
		std::cout << const_array[const_array.size()] << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
