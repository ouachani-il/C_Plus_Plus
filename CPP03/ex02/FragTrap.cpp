/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:52:48 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/07 00:09:55 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "FragTrap.hpp"


FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap default constructor is called." << std::endl;
	_name = "Default";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap parametric constructor is called." << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	
}
FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
	*this = src;
	std::cout << "FragTrap copy constructor called for " << this->_name << "." << std::endl;
}
FragTrap&	FragTrap::operator=(FragTrap const & rhs){
	if ( this != &rhs ){
		this->_name = rhs._getName();
		this->_attackDamage = rhs._getAttackDamage();
		this->_energyPoints = rhs._getEnergyPoints();
		this->_hitPoints = rhs._getHitPoints();
		std::cout << "FragTrap copy assignment operator called for " << this->_name << std::endl;
	}
	return *this;
}
FragTrap::~FragTrap(void){
	std::cout << "FragTrap destructor is called for " << this->_name << std::endl;
}

void 			FragTrap::highFivesGuys(void){
	std::cout << this->_name << ": High fives ?" << std::endl;
}

