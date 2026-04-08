#include "BitcoinExchange.hpp"
 
BitcoinExchange::BitcoinExchange() {}
 
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}
 
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _db = other._db;
    return *this;
}
 
BitcoinExchange::~BitcoinExchange() {}

 
std::string BitcoinExchange::trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}
 
bool BitcoinExchange::isValidDate(const std::string &date)
{
    // Must be exactly "YYYY-MM-DD"
    if (date.size() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
 
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue ;
        if (date[i] < '0' || date[i] > '9')
            return (false);
    }
 
    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());
 
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
 
    // Days per month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
    // Leap year
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leap)
        daysInMonth[1] = 29;
 
    if (day > daysInMonth[month - 1])
        return (false);
 
    return (true);
}
 
bool BitcoinExchange::isValidValue(const std::string &valueStr, double &value)
{
    std::istringstream iss(valueStr);
    iss >> value;
 
    // Check the whole string was consumed
    if (iss.fail() || !iss.eof())
        return false;
    return true;
}
 
double BitcoinExchange::getRate(const std::string &date)
{
    // lower_bound gives first key >= date
    std::map<std::string, double>::iterator it = _db.lower_bound(date);
 
    if (it == _db.end() || it->first != date)
    {
        // No exact match — step back to get the closest lower date
        if (it == _db.begin())
            return -1; // date is before the entire database
        --it;
    }
    return it->second;
}
 
// ── public methods ────────────────────────────────────────────────────────────
 
void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");
 
    std::string line;
    std::getline(file, line); // skip header "date,exchange_rate"
 
    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.empty())
            continue ;
 
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue ;
 
        std::string date  = trim(line.substr(0, comma));
        std::string rateStr = trim(line.substr(comma + 1));
 
        double rate;
        std::istringstream iss(rateStr);
        iss >> rate;
        if (iss.fail())
            continue ;
 
        _db[date] = rate;
    }
}
 
void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
 
    std::string line;
    std::getline(file, line); // skip header "date | value"

    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.empty())
            continue ;
 
        // Split on " | "
        size_t pipe = line.find(" | ");
        if (pipe == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
 
        std::string date     = trim(line.substr(0, pipe));
        std::string valueStr = trim(line.substr(pipe + 3));
 
        // Validate date
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
 
        // Validate value
        double value;
        if (!isValidValue(valueStr, value))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
 
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue ;
        }
 
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue ;
        }
 
        // Look up rate
        double rate = getRate(date);
        if (rate < 0)
        {
            std::cout << "Error: bad input => " << date << " (date out of range)" << std::endl;
            continue ;
        }
 
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
}
