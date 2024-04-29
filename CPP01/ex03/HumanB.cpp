/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:40:14 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/29 17:38:54 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
	this->_weap = NULL;
}
HumanB::~HumanB(void){
}
void	HumanB::_setWeapon(Weapon& weap){
	this->_weap = &weap;
}
void	HumanB::attack(void) const{
	if (this->_weap != NULL && this->_weap->_getType() != "")
		std::cout << this->_name << "attacks with their " << this->_weap->_getType() << std::endl;
	else
		std::cout << this->_name << "doesn't have a weapon to attack." << std::endl;
}
