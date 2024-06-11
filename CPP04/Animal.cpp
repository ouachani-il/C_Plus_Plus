/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 06:50:36 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/11 07:33:41 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void){
	_type = "Default";
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {    
	std::cout << "Animal parametric constructor is called" << std::endl;
}
Animal::Animal(Animal const &src){
	std::cout << "Animal copy constructor is called" << std::endl;
	*this = src;
}

Animal::~Animal(void){
	std::cout << "Animal destructor is called" << std::endl;
}
Animal  &Animal::operator=(Animal const &rhs){
	if ( this != &rhs ){
		this->_type = rhs._type;
	}
	std::cout << "Animal copy assignement oprator  is called" << std::endl;
	return *this;
}