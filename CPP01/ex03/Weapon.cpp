/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:04:04 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/05/01 10:30:20 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	this->_type = type;
}
Weapon::~Weapon(void){}

void	Weapon::setType(std::string type) //: _type(type)
{
	this->_type = type;
}

const std::string&	Weapon::getType(void) const{
	return this->_type;
}