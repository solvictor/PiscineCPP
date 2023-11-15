/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:49:01 by vegret            #+#    #+#             */
/*   Updated: 2023/11/15 18:39:00 by vegret           ###   ########.fr       */
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

static bool isValid(int ) const {
	if (_year < 1900 || _day <= 0)
		return false;
	switch (_month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return _day <= 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return _day <= 30;
	case 2:
		return _day <= (isLeap() ? 29 : 28);
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

	if (date.size() > 10 || !(isdigit(date[0]) && isdigit(date[1])
							&& isdigit(date[2]) && isdigit(date[3])
							&& date[4] == '-'
							&& isdigit(date[5]) && isdigit(date[6])
							&& date[7] == '-'
							&& isdigit(date[8]) && isdigit(date[9])))
		throw std::runtime_error("Error: bad input => " + line);

	int year = std::atoi(date.c_str());
	int month = std::atoi(date.c_str() + 5);
	int day = std::atoi(date.c_str() + 8);

	if (month > 12 || month < 1 || day > 31 || day < 1
		|| (month == 2 && __isleap(year) ))
		throw std::runtime_error("Error: bad input => " + line);
 
	std::cout << date << std::endl;
	return date;
}

static float parse_rate(std::string& line) {
	(void) line;
	return 0.0f;
}

static float parse_price(std::string& line) {
	(void) line;
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

	if (!std::getline(input_data, line) || line != "date,exchange_rate") {
		input_data.close();
		throw std::runtime_error("Error: bad file format");
	}

	while (std::getline(input_data, line)) {
		try {
			std::pair<std::string, float> pair;

			pair.first = parse_date(line, ','); // TODO Finir
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

void Exchanger::display_data(std::map<std::string, float>& data, char* path) {
	return;
	std::ifstream input_data(path);

	if (is_dir(path) || !input_data.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;

	if (!std::getline(input_data, line) || line != "date | value") {
		input_data.close();
		throw std::runtime_error("Error: bad file format");
	}
	
 	while (std::getline(input_data, line)) {
		try {
			std::string date = parse_date(line, '|'); // TODO Finir
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
