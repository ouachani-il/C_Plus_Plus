/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:03:21 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/06 23:09:43 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"


ScavTrap::ScavTrap(void) : ClapTrap("Default") {
	std::cout << "ScavTrap default constructor is called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardMode = false;
	
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap parametric constructor is called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardMode = false;
	
}
ScavTrap::ScavTrap(ScavTrap const & ScavTrap) : ClapTrap(ScavTrap) {
	*this = ScavTrap;
	std::cout << "ScavTrap copy constructor called for " << this->_name << "." << std::endl;
}
ScavTrap&	ScavTrap::operator=(ScavTrap const & rhs){
	if ( this != &rhs ){
		this->_name = rhs._getName();
		this->_attackDamage = rhs._getAttackDamage();
		this->_energyPoints = rhs._getEnergyPoints();
		this->_hitPoints = rhs._getHitPoints();
		std::cout << "ScavTrap copy assignment operator called for " << this->_name << std::endl;
	}
	return *this;
}
ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap destructor is called for " << this->_name << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if ( this->_energyPoints <= 0 ){
		std::cout << "ScavTrap has no longer energy points !!" << std::endl;
		return ;
	}
	if ( this->_hitPoints <= 0 ){
		std::cout << "ScavTrap is dead, it can't attack !!" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDamage << " points of damage !" << std::endl;
}

void 			ScavTrap::guardGate(void){
	if (this->_guardMode)
		std::cout << "ScavTrap is already in Gate keeper mode." << std::endl;
	else
		std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
	this->_guardMode = true;
}

bool			ScavTrap::getGuardMode(void) const{
	return this->_guardMode;
	}
