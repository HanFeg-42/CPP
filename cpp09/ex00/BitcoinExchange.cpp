#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string& filename) {
	std::ifstream input(DATA);
	std::string line;

	if (!input.is_open())
		throw std::runtime_error("Can't open file");
	std::getline(input, line);// i skipped the first line
	while (std::getline(input, line)) {
		std::string key = line.substr(0, POS_VALUE);
		float value = line.substr(POS_VALUE + 1);
		_data[key] = value; 
	}
	input.close();
}

int parseDate(std::string& date)
{
	if (date.size() != 11)
		std::cout << "Error: not a valid date." << std::endl;

	// yyyy-mm-dd
	// 0123456789

	if (date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad date format!" << std::endl;
		return 0;
	}
	std::string m = substr(5, 2);
	std::string d = substr(8, 2);
	std::stringstream sm(m);
	std::stringstream sd(d);
	int day, month;
	sd >> day;
	sm >> month;
	if (day > 31 || day < 1 || month > 12 || month < 1)
	{
		std::cout << "Error: bad date format!" << std::endl;
		return 0;
	}

	return 1;
}

int parseValue(std::string value)
{

}

float	getTotalPrice(std::string value)
{

}

void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream input(DATA);
	std::string line;

	if (!input.is_open())
		throw std::runtime_error("Can't open file");
	std::getline(input, line);// i skipped the first line
	while (std::getline(input, line)) {
		int pos = line.find('|');
		if (pos == std::string::npos)
			std::cout << "Error: bad input => " << line << std::endl;
		std::string date = line.substr(0, pos - 1);
		std::string value = line.substr(pos + 1);
		if (!parseDate(date) || !parseValue(value)) // i suppose that they throw error
			continue;
		// .... a lot of code
		std::cout << date << "=>" << value << "= " << getTotalPrice(value);
	}
}
