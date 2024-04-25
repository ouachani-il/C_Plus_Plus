/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:40:14 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/25 22:33:05 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void){
	this->_name = "";
}
HumanB::HumanB(Weapon weap){
	this->_weap = weap;
}
void    HumanB::attack(std::string type) const{
	std::cout << this->_name << "attacks with their " << this->_weap._getType() << std::endl;
}
HumanB::_setWeapon(Weapon weap){
	this->_weap = weap;
}