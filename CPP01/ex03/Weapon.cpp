/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:04:04 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/29 17:38:03 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	this->_type = type;
}
Weapon::~Weapon(void){}

void	Weapon::_setType(std::string type) //: _type(type)
{
	this->_type = type;
}

const std::string&	Weapon::_getType(void) const{
	return this->_type;
}