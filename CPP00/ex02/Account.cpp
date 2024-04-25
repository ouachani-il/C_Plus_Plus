/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:24:55 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/25 13:16:14 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

#include "Account.hpp"

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
	return (this->_nbWithdrawals)
}
void	Account::displayAccountsInfos( void ){
	for(Account )
	{
		
	}
 	std::cout << Account::_displayTimestamp
				<< " index" << 

}
Account::Account( int initial_deposit ){
	this->_amount = initial_deposit;
}
Account::~Account( void ){
	
}
void	Account::makeDeposit( int deposit ){
	Account::_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
}
bool	Account::makeWithdrawal( int withdrawal ){
	Account::_totalNbWithdrawals += 1;
	this->_nbWithdrawals += 1;
}
int		Account::checkAmount( void ) const{
	
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
	auto now = std::chrono::system_clock::now();

	// Converts the actual time in `std::time_t`
	std::time_t timeNow = std::chrono::system_clock::to_time_t(now);

	// Converts `std::time_t` in `std::tm` pour formatage
	std::tm* localTime = std::localtime(&timeNow);

	// Afficher le temps avec formatage
 	std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "]"
			 << std::flush;

}
	Account::Account( void ){
		Account::_accountIndex = Account::_nbAccounts;
		Account::_nbAccounts += 1;
	}

