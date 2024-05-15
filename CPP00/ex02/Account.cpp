/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:24:55 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/15 10:56:47 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (Account::_totalNbWithdrawals);
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
}

void	Account::displayAccountsInfos( void ){
//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts 
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
	
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
				<< ";amount:" << this->_amount
				<< ";created"
				<< std::endl;
}

Account::~Account( void ){
	this->_nbAccounts--;
	
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
				<< ";amount:" << this->_amount
				<< ";closed"
				<< std::endl;
}

void	Account::makeDeposit( int deposit ){
	this->_displayTimestamp();
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";" << std::flush;
	_amount += deposit;
	std::cout << "deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposit:" << _nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal ){
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:" << std::flush;
	if ( withdrawal > checkAmount()){
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";" << std::flush;
	Account::_totalNbWithdrawals ++;
	this->_nbWithdrawals ++;
	this->_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";"
				<< "nb_deposit:" << _nbDeposits << std::endl;
	return true;
}


int		Account::checkAmount( void ) const{
	return this->_amount;
}
void	Account::displayStatus( void ) const{
	this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals << std::endl;
}
