/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:45:15 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/31 20:28:25 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

//respecter la forme canonique dans les sous classes !!!!
DiamondTrap::DiamondTrap(std::string name) : public ClapTrap{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->
}

DiamondTrap::DiamondTrap(DiamondTrap & const rhs){
	*this = clapTrap;
	std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}

DiamondTrap&	operator=(DiamondTrap const& rhs) : public ClapTrap {
	
	if (this != &rhs){
		this->_name = rhs._getName();
		this->_attackDamage = rhs._getAttackDamage();
		this->_energyPoints = rhs._getEnergyPoints();
		this->_hitPoints = rhs._getHitPoints();
		std::cout << "DiamondTrap copy assignment operator called for " << this->_name << std::endl;
	}
	return (*this);
}


/*if faut que je mette le mot virtual devant les methodes
qui sont intermediare pour dire qu'il doit se referer directement a ClapTrap pour ne pas s'embrouiller 
par quelle ss classe passer  a mieux comprendre...*/