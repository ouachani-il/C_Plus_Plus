/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:02:27 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/11 13:03:26 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal(){
    _type = "WrongCat";
	std::cout << "WrongCat default constructor is called" << std::endl;

}

WrongCat::WrongCat(std::string type) : WrongAnimal( ){    
    _type = type;
	std::cout << "WrongCat parametric constructor is called" << std::endl;
}
WrongCat::WrongCat(WrongCat const &src) : WrongAnimal("WrongCat Parent"){
	_type = "WrongCat";
	std::cout << "WrongCat copy constructor is called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat destructor is called" << std::endl;
}
WrongCat  &WrongCat::operator=(WrongCat const &rhs){
	if ( this != &rhs ){
		this->_type = rhs._type;
	}
	std::cout << "WrongCat copy assignement oprator  is called" << std::endl;
	return *this;
}

void	WrongCat::makeSound(void) const{
	std::cout << "miaowww !" << std::endl;
}