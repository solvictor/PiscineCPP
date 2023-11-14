/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:48:59 by vegret            #+#    #+#             */
/*   Updated: 2023/11/14 17:37:23 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>

class Exchanger {
	public:
		Exchanger();
		Exchanger(const Exchanger& source);
		~Exchanger();

		Exchanger& operator=(const Exchanger& source);

		std::map<std::string, float> parse_data(char* path);
		void display_data(std::map<std::string, float> data, char* path);
};

#endif