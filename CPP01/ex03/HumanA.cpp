/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:40:00 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/01 10:37:30 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weap) : _name(name), _weap(weap) {
}
HumanA::~HumanA(void){
}
void	HumanA::attack(void) const{
	if (this->_weap.getType() != "")
		std::cout << this->_name << " attacks with their " << this->_weap.getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have a weapon to attack." << std::endl;
	
}