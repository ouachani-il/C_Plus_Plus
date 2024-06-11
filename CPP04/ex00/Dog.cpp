/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:25:00 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/11 16:59:53 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog Parent"){
    _type = "Dog";
	std::cout << "Animal default constructor is called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type + " Parent") { 
    _type = type;   
	std::cout << "Dog parametric constructor is called" << std::endl;
}
Dog::Dog(Dog const &src): Animal("Dog Parent"){
	std::cout << "Dog copy constructor is called" << std::endl;
	*this = src;
}

Dog::~Dog(void){
	std::cout << "Dog destructor is called" << std::endl;
}
Dog  &Dog::operator=(Dog const &rhs){
	if ( this != &rhs ){
		this->_type = rhs._type;
	}
	std::cout << "Dog copy assignement oprator  is called" << std::endl;
	return *this;
}

void	Dog::makeSound(void) const{
	std::cout << "habhabhab !!" << std::endl;
}