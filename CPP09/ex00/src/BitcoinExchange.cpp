/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:10:31 by ilham_oua         #+#    #+#             */
/*   Updated: 2025/03/01 22:12:20 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

// Function to trim leading and trailing whitespace (C++98 compatible)
static std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return ""; // String contains only spaces
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

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
    
}

/********************* loadPrices**************************/
void    BitcoinExchange::loadPrices(std::string const & filename){
        // Ouvrir le fichier en lecture
    std::ifstream file(filename.c_str());

    // Vérifier si le fichier est bien ouvert
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
        return ;
    }

    // Lire le fichier ligne par ligne
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }


    std::map<std::string, double> prices;
    std::string line = "2024-02-26, 123.45 "; // Example input line

    std::istringstream iss(line);
    std::string date_str, price_str;

    // Extract date and price as strings
    if (std::getline(iss, date_str, ',') && std::getline(iss, price_str)) {
        date_str = trim(date_str);
        price_str = trim(price_str);

        // Convert price string to double safely using std::strtod
        char *end;
        double price = std::strtod(price_str.c_str(), &end);
        
        if (*end == '\0') { // Ensure the entire string was converted
            prices[date_str] = price;
        } else {
            std::cerr << "Error: Invalid price format: " << price_str << std::endl;
        }
    }

    // Print stored prices
    std::map<std::string, double>::const_iterator it;
    for (it = prices.begin(); it != prices.end(); ++it) {
        std::cout << "Date: " << it->first << ", Price: " << it->second << std::endl;
    }


    // Fermer le fichier (automatique à la destruction de file)
    file.close();

}
std::map <std::string, double> const &  BitcoinExchange::getPrices() const{
    return _prices;
}
bool    BitcoinExchange::isValidFormat(std::string const & date_in) const{
    if (isdigit(date_in))
}
void    BitcoinExchange::InputLineProcessing(std::string const & ln){
    
}
