/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:49:01 by vegret            #+#    #+#             */
/*   Updated: 2023/11/14 19:24:30 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "BitcoinExchange.hpp"

Exchanger::Exchanger() {}

Exchanger::Exchanger(const Exchanger& source) { (void) source; }

Exchanger::~Exchanger() {}

Exchanger& Exchanger::operator=(const Exchanger& source) {
	(void) source;
	return *this;
}

static bool	is_dir(const char* path)
{
	struct stat buf;
	stat(path, &buf);
	return (S_ISDIR(buf.st_mode));
}

static std::string parse_date(std::string& line) {
	
	return "";
}

static float parse_rate(std::string& line) {
	return 0.0f;
}

static float parse_price(std::string& line) {
	return 0.0f;
}

static float closest_rate(std::map<std::string, float> data, std::string& date) {
	std::map<std::string, float>::iterator it = data.find(date);

	if (it != data.end())
		return (*it).second;
	
	it = data.begin();
	std::pair<std::string, float> best = *it;
	it++;

	while (it != data.end()) {
		if ((*it).first < date && (*it).first > best.first)
			best = *it;
		it++;
	}

	return best.second;
}

std::map<std::string, float> Exchanger::parse_data(char* path) {
	std::ifstream input_data(path);

	if (is_dir(path) || !input_data.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::map<std::string, float> data;

	std::string line;

	while (std::getline(input_data, line)) {
		try {
			std::pair<std::string, float> pair;

			pair.first = parse_date(line); // TODO Finir
			pair.second = parse_rate(line);

			data.insert(pair);
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	input_data.close();

	return data;
}

void display_data(std::map<std::string, float> data, char* path) {
	std::ifstream input_data(path);

	if (is_dir(path) || !input_data.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;

	while (std::getline(input_data, line)) {
		try {
			std::string date = parse_date(line); // TODO Finir
			float price = parse_price(line);
			float rate = closest_rate(data, date);

			std::cout << date << " => " << price << " = " << price * rate << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	input_data.close();
}
