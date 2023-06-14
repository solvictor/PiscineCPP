/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:52:30 by vegret            #+#    #+#             */
/*   Updated: 2023/06/14 15:35:24 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*uppercase(char *str)
{
	int	i = 0;
	std::locale	loc;

	while (str[i])
	{
		str[i] = std::toupper(str[i], loc);
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1 ; i < argc ; i++)
		std::cout << uppercase(argv[i]);
	std::cout << std::endl;
	return 0;
}
