/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:19:09 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/11 13:31:43 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    _type = "WrongAnimal";
	std::cout << "Animal default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) { 
    _type = type;   
	std::cout << "WrongAnimal parametric constructor is called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &src){
	_type = "WrongAnimal";
	std::cout << "WrongAnimal copy constructor is called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor is called" << std::endl;
}
WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &rhs){
	if ( this != &rhs ){
		this->_type = rhs._type;
	}
	std::cout << "WrongAnimal copy assignement oprator  is called" << std::endl;
	return *this;
}
void	WrongAnimal::makeSound(void) const{
	std::cout << "Wrong Sound !!" << std::endl;

}
std::string	WrongAnimal::getType(void) const{
	return ( _type );
}
