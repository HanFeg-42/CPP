#include "BitcoinExchange.hpp"
#include <ifstream>
#include <string>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(cosnt BitcoinExchange& other) {}
BitcoinExchange& BitcoinExchange::operator=(cosnt BitcoinExchange& other) {}
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

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream input(DATA);
    std::string line;

    if (!input.is_open())
        throw std::runtime_error("Can't open file");
    std::getline(input, line);// i skipped the first line
    while (std::getline(input, line)) {
        int pos = line.find('|');
        if (pos == std::string::npos)
            std::cout << "Error: bad input => 2001-42-42\n";
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos);
        parseDate(date);
        parseValue(value);
        // .... a lot of code 
        std::cout << date << "=>" << value << "= " << totalPrice;
    }
}