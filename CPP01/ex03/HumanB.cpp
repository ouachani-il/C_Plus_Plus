/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:40:14 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/26 17:02:03 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void){
	this->_name = "";
}
HumanB::HumanB(Weapon weap){
	this->_weap = weap;
}
void    HumanB::attack(void) const{
	std::cout << this->_name << "attacks with their " << this->_weap._getType() << std::endl;
}
void	HumanB::_setWeapon(Weapon weap){
	this->_weap = weap;
}