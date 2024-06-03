/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:38:28 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/03 16:57:15 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap constructor is called" << std::endl;
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
	std::cout << "ClapTrap destructor is called for " << this->_name << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if ( this->_energyPoints <= 0 ){
		std::cout << "Claptrap has no longer energy points !!" << std::endl;
		return ;
	}
	if ( this->_hitPoints <= 0 ){
		std::cout << "Claptrap is dead, it can't attack !!" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ClapTrap" << this->_name << "attacks" << target << ", causing"
	<< this->_attackDamage << "of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints < amount){
		std::cout << "not enough hit points to take the damage : " 
		<< this->_name << " is dead" << std::endl;
		_hitPoints = 0;
	}
	_hitPoints -= amount;
	std::cout << this->_name << " takes advantage of " 
	<< amount << "." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
	if (_energyPoints < amount)
	{
		std::cout << "ClapTrap " << _name 
			<< " can't be repaired: unsafficient energy points !!" << std::endl;
	}
	std::cout << this->_name << " is repared with " << amount
	<< std::endl;
}

/********Getteurs et setteurs  *********/
std::string	ClapTrap::_getName(void) const{
	return this->_name;
}

unsigned int	ClapTrap::_getAttackDamage(void) const{
	return this->_attackDamage;
}

unsigned int	ClapTrap::_getEnergyPoints(void) const{
	return this->_energyPoints;
}

unsigned int	ClapTrap::_getHitPoints(void) const{
	return this->_hitPoints;
}

/**
 * @brief hit points represente la duree de vie elle n'est pas touchee par les attack, 
 * le dommage est mis ds cet exo a 0, il n'y a que l'energie qui est touchee
 * 
 */