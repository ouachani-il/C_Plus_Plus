/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:40:00 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/26 17:02:44 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon weap){
	this->_weap = weap;
}
HumanA::~HumanA(void){
}
void	HumanA::attack(void) const{
	std::cout << this->_name << "attacks with their " << this->_weap._getType() << std::endl;
}
void	HumanA::_setWeapon(Weapon weap){
	this->_weap = weap;
}