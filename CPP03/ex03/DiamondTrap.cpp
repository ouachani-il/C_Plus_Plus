/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:45:15 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/06 17:26:38 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

//respecter la forme canonique dans les sous classes !!!!
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), 
											FragTrap(name + "_clap_name"), 
											ScavTrap(name + "_clap_name"){
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap & const rhs) : ClapTrap(rhs._name + "_clap_name"), 
													FragTrap(rhs._name + "_clap_name"), 
													ScavTrap(rhs._name + "_clap_name"){
	*this = rhs;
	std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const& rhs) {
	
	if (this != &rhs){
		this->_name = rhs._name;
		this->_attackDamage = rhs._getAttackDamage();
		this->_energyPoints = rhs._getEnergyPoints();
		this->_hitPoints = rhs._getHitPoints();
		std::cout << "DiamondTrap copy assignment operator called for " << this->_name << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void){
	
	std::cout << "DiamondTrap destructor is called for " << this->_name << std::endl;
}

void	DiamondTrap::whoAmI(){
	std::cout <<
}

void DiamondTrap::attack(const std::string &target) {
	// if ( this->_energyPoints <= 0 ){
	// 	std::cout << "ScavTrap has no longer energy points !!" << std::endl;
	// 	return ;
	// }
	// if ( this->_hitPoints <= 0 ){
	// 	std::cout << "ScavTrap is dead, it can't attack !!" << std::endl;
	// 	return ;
	// }
	// this->_energyPoints -= 1;
	// std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
	// << this->_attackDamage << " points of damage !" << std::endl;
	ScavTrap::attack(target);
}


/*if faut que je mette le mot virtual devant les methodes
qui sont intermediare pour dire qu'il doit se referer directement a ClapTrap pour ne pas s'embrouiller 
par quelle ss classe passer  a mieux comprendre...*/