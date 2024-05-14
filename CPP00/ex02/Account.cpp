/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:24:55 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/14 13:10:56 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (this->_nbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (this->_nbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	Account::_displayTimestamp;
	std::cout << " accounts:" << Account::_nbAccounts 
			<< ";total:" << Account::_totalAmount
			<< ";deposits:" << Account::_totalNbDeposits
			<< ";withdrawals:" << Account::_totalNbWithdrawals
			<< std::endl;
	
}

Account::Account( int initial_deposit ){
	this->_amount = initial_deposit;
	this->_nbAccounts ++;
	this->_accountIndex = this->_nbAccounts - 1;
	this->_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	this->_displayTimestamp;
	std::cout << " index:" << this->_accountIndex 
				<< ";amount:" << this->_amount
				<< ";created"
				<< std::endl;
}

Account::~Account( void ){
	this->_nbAccounts--;
	
	this->_displayTimestamp;
	std::cout << " index:" << this->_accountIndex 
				<< ";amount:" << this->_amount
				<< ";closed"
				<< std::endl;
}

void	Account::makeDeposit( int deposit ){
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";" << std::flush;
	_amount += deposit;
	std::cout << "deposit:" << deposit << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_deposit:" << _nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal ){
	if ( withdrawal > checkAmount())
		std::cout <<
	Account::_totalNbWithdrawals += 1;
	this->_nbWithdrawals += 1;
}


int		Account::checkAmount( void ) const{
	return this->_amount;
}
void	Account::displayStatus( void ) const{
	std::cout << Account::_displayTimestamp
				<< " accounts:" << Account::_nbAccounts
				<< "total:" << Account::_totalAmount
				<< "deposits:" << Account::_totalNbDeposits
				<< "withdrawals:" << Account::_totalNbWithdrawals
				<< std::endl;
}
void	Account::_displayTimestamp( void ){
	std::time_t result = std::time(NULL);

	std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&result)->tm_year
				<< std::setw(2) << 1 + std::localtime(&result)->tm_mon
				<<  std::setw(2) << std::localtime(&result)->tm_mday
				<<  "_"
				<<  std::setw(2) << std::localtime(&result)->tm_hour
				<<  std::setw(2) << std::localtime(&result)->tm_min
				<<  std::setw(2) << std::localtime(&result)->tm_sec 
				<< "] " << std::flush;
	/*auto now = std::chrono::system_clock::now();

	// Converts the actual time in `std::time_t`
	std::time_t timeNow = std::chrono::system_clock::to_time_t(now);

	// Converts `std::time_t` in `std::tm` pour formatage
	std::tm* localTime = std::localtime(&timeNow);

	// Afficher le temps avec formatage
 	std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "]"
			 << std::flush;*/

}
