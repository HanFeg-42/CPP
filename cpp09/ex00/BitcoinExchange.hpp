#pragma once

#include <iostream>
#include <exception>
#include <map>

#define DATA "data.csv"
#define POS_VALUE 10

class BitcoinExchange {
private:
	std::map<std::string, float> _data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadData(const std::string& filename);
	void processInput(const std::string& filename);
};