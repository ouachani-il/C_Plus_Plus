/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:38:28 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/05/28 22:57:25 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "Constructor is called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const & clapTrap){
	*this = clapTrap;
	std::cout << "ClapTrap copy constructor called for " << this->_name << std::endl;
}
ClapTrap&	ClapTrap::operator=(ClapTrap const & rhs){
	if ( this != &rhs ){
		this->_name = rhs._getName();
		this->_attackDamage = rhs._getAttackDamage();
		this->_energyPoints = rhs._getEnergyPoints();
		this->_hitPoints = rhs._getHitPoints();
		std::cout << "ClapTrap copy assignment operator called for " << this->_name << std::endl;
	}
	return *this;
}
ClapTrap::~ClapTrap(void){
	std::cout << "Destructor is called for " << this->_name << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	
	std::cout << "ClapTrap" << this->_name << "attacks" << target << ", causing"
	<< "1 points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints < amount){
		std::cout << "not enough hit points to take the damage : " 
		<< this->_name << " is dead" << std::endl;
		_hitPoints = 0;
	}
	std::cout << this->_name << " take advantage of " 
	<< amount << "." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
	std::cout << this->_name << " is repared with " << amount
	<< std::endl;
}

/********Getteurs et setteurs  *********/
std::string	ClapTrap::_getName(void){
	return this->_name;
}

int	ClapTrap::_getAttackDamage(void){
	return this->_attackDamage;
}

int	ClapTrap::_getEnergyPoints(void){
	return this->_energyPoints;
}

int	ClapTrap::_getHitPoints(void){
	return this->_hitPoints;
}