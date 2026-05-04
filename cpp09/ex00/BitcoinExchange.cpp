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

int parseDate(std::string date)
{
    if (date.size() != 11)
        std::cout << "Error: not a valid date." << std::endl;

    std::string year, month, day;
    std::istringstream is(date);
    std::getline(is, year, '-');
    std::getline(is, month, '-');
    std::getline(is, day, '-');
    
}

int parseValue(std::string value)
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
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos);
        if (!parseDate(date) || !parseValue(value)) // i suppose that they throw error
            continue;
        // .... a lot of code
        std::cout << date << "=>" << value << "= " << getTotalPrice(value);
    }
}
