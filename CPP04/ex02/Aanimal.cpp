/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:43:00 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/13 02:49:45 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void){
	_type = "Default";
	std::cout << "AAnimal default constructor is called" << std::endl;
}

/*AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "AAnimal parametric constructor is called" << std::endl;
}*/
AAnimal::AAnimal(AAnimal const &src){
	std::cout << "AAnimal copy constructor is called" << std::endl;
	_type = src._type;
}

AAnimal::~AAnimal(void){
	std::cout << "AAnimal destructor is called" << std::endl;
}
AAnimal  &AAnimal::operator=(AAnimal const &rhs){
	if ( this != &rhs ){
		this->_type = rhs._type;
	}
	std::cout << "AAnimal copy assignement oprator  is called" << std::endl;
	return *this;
}

std::string	AAnimal::getType(void) const{
	return ( _type );
}

void	AAnimal::makeSound(void) const{
	std::cout << "Each AAnimal has a specific sound" << std::endl;
}

Brain	*AAnimal::getBrain(void) const {
	return (NULL);
}