/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:04:04 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/25 22:23:36 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	this->_type = type;
}
Weapon::~Weapon(void){}

void    Weapon::_setType(std::string type) //: _type(type)
{
	this->_type = type;
}

std::string	Weapon::_getType(void) const{
	return this->_type;
}