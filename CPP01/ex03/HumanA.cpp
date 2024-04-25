/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:40:00 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/25 22:32:34 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon weap){
	this->_weap = weap;
}
HumanA::~HumanA(void){
}
void    HumanA::attack(std::string type) const{
	std::cout << this->_name << "attacks with their " << this->_weap._getType() << std::endl;
}
HumanA::_setWeapon(Weapon weap){
	this->_weap = weap;
}