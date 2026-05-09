#include "BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData()
{
	std::ifstream input(DATA);
	std::string line;
	double value;

	if (!input.is_open())
		throw std::runtime_error("Can't open file");
	std::getline(input, line);
	while (std::getline(input, line))
	{
		std::string key = line.substr(0, POS_VALUE);
		std::string nbr = line.substr(POS_VALUE + 1);
		std::stringstream ss(nbr);
		ss >> value;
		_data[key] = value; 
	}
	input.close();
}

int isDateValid(int y, int m, int d)
{
	struct tm t;

	std::memset(&t, 0, sizeof(struct tm));
	t.tm_year = y - 1900;
	t.tm_mon = m - 1;
	t.tm_mday = d;

	int oldY = t.tm_year;
	int oldM = t.tm_mon;
	int oldD = t.tm_mday;

	if (mktime(&t) == -1) return false;

	return (t.tm_year == oldY && t.tm_mon == oldM && t.tm_mday == oldD);
}

int parseDate(std::string date)
{
	if (date.size() != 10)
	{
		std::cout << "Error: not a valid date." << std::endl;
		return 0;
	}
	if (date[4] != '-' || date[7] != '-' || std::count(date.begin(), date.end(), '-') != 2)
	{
		std::cout << "Error: bad date format!" << std::endl;
		return 0;
	}
	date[4] = ' ';
	date[7] = ' ';
	std::stringstream ss(date);
	int day, month, year;
	ss >> year;
	ss >> month;
	ss >> day;
	if (ss.fail() || !isDateValid(year, month, day))
	{
		std::cout << "Error: invalid date!" << std::endl;
		return 0;
	}
	return 1;
}

double parseValue(std::string value)
{
	std::stringstream s(value);
	double n;

	s >> n;
	if (s.fail())
	{
		std::cout << "Error: invalid number." << std::endl;
		return 0;
	}
	if (n < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 0;
	}
	if (n > INT_MAX)
	{
		std::cout << "Error: too large a number." << std::endl;
		return 0;	
	}
	return n;
}

double BitcoinExchange::getPrice(std::string key)
{
	std::map<std::string, double>::iterator it;
	it = _data.lower_bound(key);
	return (it->second);
}

void BitcoinExchange::processInput(const char* filename) {
	std::ifstream	input(filename);
	std::string		line, date, strValue;
	size_t			pos;
	double			value = 0.0;

	if (!input.is_open())
		throw std::runtime_error("Can't open file");
	std::getline(input, line);
	while (std::getline(input, line)) {
		pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, pos - 1);
		strValue = line.substr(pos + 1);
		if (!parseDate(date) || !(value = parseValue(strValue)))
			continue;
		std::cout << date << " => " << value << " = ";
		std::cout << value * getPrice(date) << std::endl;
	}
}
