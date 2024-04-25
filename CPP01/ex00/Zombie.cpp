/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:38:21 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/25 16:02:25 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->_name = name;
}
Zombie::~Zombie(void){
	std::cout << "Zombie " << this->_name << " is destroyed" << std::endl;
}
void	Zombie::annonce(void) const{
	std::cout << this->_name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
std::string	Zombie::_getName(void) const{
	return (this->_name);
}

