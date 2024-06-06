/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:38:28 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/06 10:02:45 by ilouacha         ###   ########.fr       */
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
		this->_name = rhs.getName();
		this->_attackDamage = rhs.getAttackDamage();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_hitPoints = rhs.getHitPoints();
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
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDamage << " points of damage !" << std::endl;
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
			<< " can't be repaired: unsufficient energy points !!" << std::endl;
	}
	this->_hitPoints += amount;
	this->_energyPoints --;
	std::cout << this->_name << " is repared with " << amount << "." << std::endl;
}

/********Getteurs et setteurs  *********/
std::string	ClapTrap::getName(void) const{
	return this->_name;
}

unsigned int	ClapTrap::getAttackDamage(void) const{
	return this->_attackDamage;
}

unsigned int	ClapTrap::getEnergyPoints(void) const{
	return this->_energyPoints;
}

unsigned int	ClapTrap::getHitPoints(void) const{
	return this->_hitPoints;
}

void	ClapTrap::setName(std::string name){
	this->_name = name;
}
void	ClapTrap::setHitPoints(unsigned int hitPoints){
	this->_hitPoints = hitPoints;
}
void	ClapTrap::setEnergyPoints(unsigned int energyPoints){
	
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(unsigned int attackD){
	this->_attackDamage = attackD;
}

/**
 * @brief hit points represente la duree de vie elle n'est pas touchee par les attack, 
 * le dommage est mis ds cet exo a 0, il n'y a que l'energie qui est touchee
 * 
 */