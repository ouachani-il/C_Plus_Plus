/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:10:31 by ilham_oua         #+#    #+#             */
/*   Updated: 2025/03/14 22:30:13 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Function to trim leading and trailing whitespace (C++98 compatible)
/*static std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return ""; // String contains only spaces
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}*/

/******************Canonical forms *********************************/
BitcoinExchange::BitcoinExchange(){
    std::cout << "BitcoinExchange constructor" << std::endl;
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const & src){
    *this = src;
}
BitcoinExchange &   BitcoinExchange::operator=(BitcoinExchange const & rhs){
    _prices = rhs._prices;
    return (*this);
}
BitcoinExchange::~BitcoinExchange(){
    std::cout << "BitcoinExchange destructor" << std::endl;  
}

/********************* loadPrices**************************/
std::pair<std::string, double>  BitcoinExchange::_findDateClose(const std::string &target_date) const{
    std::map<std::string, double>::const_iterator it = _prices.lower_bound(target_date);// first >=
    if (it == _prices.end() || it->first > target_date) {
        if (it == _prices.begin()) {
            return std::make_pair("", 0.0); //an empty string ""., No available date before target_date
        }
        --it;
    }
    return *it;  
}

/********************* loadPrices**************************/
void    BitcoinExchange::loadPrices(std::string const & filename){
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open the data_base file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if(!line.empty())
        {
            // Create an istringstream object from the string
            std::istringstream iss(line);
            std::string date_in, price_str;
            if (std::getline(iss, date_in, ',') && std::getline(iss, price_str))
            {
                date_in.erase(0, date_in.find_first_not_of(" \t\n\r"));
                date_in.erase(date_in.find_last_not_of(" \t\n\r") + 1);
                price_str.erase(0, price_str.find_first_not_of(" \t\n\r"));
                price_str.erase(price_str.find_last_not_of(" \t\n\r") + 1);
                std::istringstream price_stream(price_str);
                double price;
                price_stream >> price;
                _prices[date_in] = price;
            }
        }
    }
    file.close();
}

/**
check wheather the date has a valid format
 */
bool    BitcoinExchange::isValidFormat(std::string const & date_in) const{
        // Check if the string is exactly 10 characters long
    if (date_in.length() != 10) {
        return false;
    }

    // Check the format: YYYY-MM-DD
    if (date_in[4] != '-' || date_in[7] != '-') {
        return false;
    }

    // Validate year, month, and day components
    for (int i = 0; i < 4; ++i) {
        if (!std::isdigit(date_in[i])) {
            return false;
        }
    }

    for (int i = 5; i < 7; ++i) {
        if (!std::isdigit(date_in[i])) {
            return false;
        }
    }

    for (int i = 8; i < 10; ++i) {
        if (!std::isdigit(date_in[i])) {
            return false;
        }
    }

    // Check if the year, month, and day are valid numbers
    int year, month, day;
    std::istringstream(date_in.substr(0, 4)) >> year;
    std::istringstream(date_in.substr(5, 2)) >> month;
    std::istringstream(date_in.substr(8, 2)) >> day;

    // Year should be non-negative
    if (year < 0) {
        return false;
    }

    // Month should be between 1 and 12
    if (month < 1 || month > 12) {
        return false;
    }

    // Day should be between 1 and 31, but need further validation for specific months
    if (day < 1 || day > 31) {
        return false;
    }

    // Additional validation for months with fewer days
    if (month == 2) {
        // Leap year check
        bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (leap ? 29 : 28)) {
            return false;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return false;
        }
    }

    return true;

}

/**
 * Processing input line
 */

void    BitcoinExchange::InputLineProcessing(std::string const & line){
    std::string date_in, value_str;
    std::string::size_type separator = line.find('|');

    //"no position" or an invalid position in a string.
    if (separator == std::string::npos) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    date_in = line.substr(0, separator);
    value_str = line.substr(separator + 1);

    date_in.erase(0, date_in.find_first_not_of(" \t\n\r"));
    date_in.erase(date_in.find_last_not_of(" \t\n\r") + 1);
    value_str.erase(0, value_str.find_first_not_of(" \t\n\r"));
    value_str.erase(value_str.find_last_not_of(" \t\n\r") + 1);


    if(!isValidFormat(date_in))
    {
        std::cerr << "Error: not a valid date => " << date_in << std::endl;
        return;
    }

    std::istringstream value_stream(value_str);
    double value;
    value_stream >> value;

    if (value <= 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    if (value >= 1000) {
        std::cerr << "Error: too large number." << std::endl;
        return;
    }

    std::pair<std::string, double> closest_date = _findDateClose(date_in);
    if (!closest_date.first.empty()) {
        double price = closest_date.second;
        double result = value * price;
        std::cout << date_in << " => " << value << " = " << result << std::endl;
    } else {
        std::cerr << "Error: no available date before " << date_in << "." << std::endl;
    }

}

std::map <std::string, double> const &  BitcoinExchange::getPrices() const{
    return _prices;
}

