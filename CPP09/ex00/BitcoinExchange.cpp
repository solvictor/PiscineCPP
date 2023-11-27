/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:49:01 by vegret            #+#    #+#             */
/*   Updated: 2023/11/27 18:34:56 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include "BitcoinExchange.hpp"

Exchanger::Exchanger() {}

Exchanger::Exchanger(const Exchanger& source __attribute__((unused))) {}

Exchanger::~Exchanger() {}

Exchanger& Exchanger::operator=(const Exchanger& source __attribute__((unused))) {
	return *this;
}

static bool	is_dir(const char* path)
{
	struct stat buf;
	stat(path, &buf);
	return (S_ISDIR(buf.st_mode));
}

static void trim(std::string& str) {
	std::string::iterator it = str.begin();

	while (it != str.end() && std::isspace(*it)) { 
		it = str.erase(it); 
	}

	it = str.end() - 1;
	while (it != str.begin() && std::isspace(*it)) { 
		it = str.erase(it);
		it--;
	}
}

static bool is_valid(int year, int month, int day) {
	if (year < 1900 || day < 1)
		return false;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return day <= 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return day < 31;
		case 2:
			return day <= (__isleap(year) ? 29 : 28);
		default:
			return false;
	};
}

static std::string parse_date(std::string& line, char sep) {
	std::size_t sep_index = line.find(sep);

	if (sep_index == std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);

	std::string date = line.substr(0, sep_index);

	trim(date);

	if (date.size() != 10 || !(isdigit(date[0]) && isdigit(date[1])
							&& isdigit(date[2]) && isdigit(date[3])
							&& date[4] == '-'
							&& isdigit(date[5]) && isdigit(date[6])
							&& date[7] == '-'
							&& isdigit(date[8]) && isdigit(date[9])))
		throw std::runtime_error("Error: bad input => " + line);

	int year = std::atoi(date.c_str());
	int month = std::atoi(date.c_str() + 5);
	int day = std::atoi(date.c_str() + 8);

	if (!is_valid(year, month, day))
		throw std::runtime_error("Error: bad input => " + line);

	return date;
}

static float parse_float(std::string& line, char sep, bool is_price) {
	std::size_t sep_index = line.find(sep);

	if (sep_index == std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);

	std::string str = line.substr(sep_index + 1, line.size());

	trim(str);

	if (str.size() < 1)
		throw std::runtime_error("Error: bad input => " + line);

	float f = std::atof(str.c_str());

	if (f < 0)
		throw std::runtime_error("Error: not a positive number.");

	if (is_price && f > 1000)
		throw std::runtime_error("Error: too large a number.");

	return f;
}

float Exchanger::closest_rate(std::string& date) const {
	std::map<std::string, float>::const_iterator it = _data.find(date);

	if (it != _data.end())
		return (*it).second;

	it = _data.begin();
	std::pair<std::string, float> best = *it;
	it++;

	while (it != _data.end()) {
		if ((*it).first < date && (*it).first > best.first)
			best = *it;
		it++;
	}

	return best.second;
}

void Exchanger::load_data(char* path) {
	if (is_dir(path))
		throw std::runtime_error("Error: could not open file.");

	std::ifstream input_data(path);

	if (!input_data.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;

	if (!std::getline(input_data, line) || line != "date,exchange_rate") {
		input_data.close();
		throw std::runtime_error("Error: bad file format");
	}

	while (std::getline(input_data, line)) {
		try {
			std::pair<std::string, float> pair;

			pair.first = parse_date(line, ',');
			pair.second = parse_float(line, ',', false);

			_data.insert(pair);
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	input_data.close();
}

void Exchanger::display_data(char* path) const {
	if (is_dir(path))
		throw std::runtime_error("Error: could not open file.");

	std::ifstream input_data(path);

	if (!input_data.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;

	if (!std::getline(input_data, line) || line != "date | value") {
		input_data.close();
		throw std::runtime_error("Error: bad file format");
	}
	
	while (std::getline(input_data, line)) {
		try {
			std::string date = parse_date(line, '|');
			float price = parse_float(line, '|', true);
			float rate = closest_rate(date);

			std::cout << date << " => " << price << " = " << price * rate << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	input_data.close();
}
