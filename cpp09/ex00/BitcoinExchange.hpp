#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
 
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
 
class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
 
    void loadDatabase(const std::string &filename);
    void processInput(const std::string &filename);
 
private:
    std::map<std::string, double> _db;
 
    bool        isValidDate(const std::string &date);
    bool        isValidValue(const std::string &valueStr, double &value);
    double      getRate(const std::string &date);
    std::string trim(const std::string &str);
};
 
#endif