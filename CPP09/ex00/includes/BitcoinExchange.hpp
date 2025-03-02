/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:53:53 by ilham_oua         #+#    #+#             */
/*   Updated: 2025/03/01 11:16:16 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <cctype>
#include <utility>

class BitcoinExchange {
    private:
        std::map <std::string, double>  _prices;
        std::pair<std::string, double>  _findDateClose(const std::string &target_date) const;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & src);
        BitcoinExchange &   operator=(BitcoinExchange const & rhs);
        ~BitcoinExchange();

        void    loadPrices(std::string const & filename);
        std::map <std::string, double> const &  getPrices() const;
        bool    isValidFormat(std::string const & date_in) const;
        void    InputLineProcessing(std::string const & ln);
        
};

#endif