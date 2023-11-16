/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:48:59 by vegret            #+#    #+#             */
/*   Updated: 2023/11/16 12:41:13 by vegret           ###   ########.fr       */
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
	private:
		std::map<std::string, float> _data;

	public:
		Exchanger();
		Exchanger(const Exchanger& source);
		~Exchanger();

		Exchanger& operator=(const Exchanger& source);

		void load_data(char* path);
		void display_data(char* path) const;
		float closest_rate(std::string& date) const;
};

#endif