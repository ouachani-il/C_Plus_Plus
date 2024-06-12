/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 06:50:36 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/12 16:02:08 by ilouacha         ###   ########.fr       */
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
	_type = src._type;
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

std::string	Animal::getType(void) const{
	return ( _type );
}

void	Animal::makeSound(void) const{
	std::cout << "Each animal has a specific sound" << std::endl;
}

Brain	*Animal::getBrain(void) const {
	return (NULL);
}