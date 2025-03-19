/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:07:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2025/03/19 15:37:49 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        if (argc > 2) {
            std::cerr << "Error: you must provide exactly one input file." << std::endl;
        } else {
            std::cerr << "Error: could not open file. (there is no file!)" << std::endl;
        }
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    std::string input_filename = argv[1];
    std::string data_base = "./input_files/data.csv";

    BitcoinExchange btc;
    btc.loadPrices(data_base);

    for (std::map<std::string, double>::const_iterator it = btc.getPrices().begin(); it != btc.getPrices().end(); ++it) {
        if (!btc.isValidFormat(it->first)) {
            std::cerr << "Invalid date format in csv file: " << it->first << std::endl;
            return 1;
        }
    }

    std::ifstream input_file(input_filename.c_str());
    if (!input_file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(input_file, line);
    if (line.empty()) {
        std::cerr << "Error: file is empty." << std::endl;
    }else {
        while (std::getline(input_file, line)) {
            if (!line.empty()) {
                btc.InputLineProcessing(line);
            }
        }
    }
    input_file.close();
    return 0;
}
