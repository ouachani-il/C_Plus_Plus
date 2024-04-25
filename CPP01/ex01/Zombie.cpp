/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:38:21 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/25 16:49:50 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::Zombie(std::string name){
	this->_name = name;
}
Zombie::~Zombie(void){
	std::cout << this->_name << " is destroyed" << std::endl;
}
void	Zombie::annonce(void) const{
	std::cout << this->_name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::_setName(std::string const name) {
	this->_name = name;
}

std::string	Zombie::_getName(void) const{
	return (this->_name);
}


