/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:03:21 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/04 11:28:38 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : {
	std::cout << "ScavTrap constructor is called" << std::endl;
	setName(name);
	setEnergyPoints()
	
}
ScavTrap::ScavTrap(ScavTrap const & ScavTrap){
	*this = ScavTrap;
	std::cout << "ScavTrap copy constructor called for " << this->_name << std::endl;
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
