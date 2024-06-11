/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:23:00 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/11 17:33:16 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(" Cat parent" ){
    _type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor is called" << std::endl;

}

Cat::Cat(std::string type) : Animal(type + " parent" ){    
    _type = type;
	_brain = new Brain();
	std::cout << "Cat parametric constructor is called" << std::endl;
}
Cat::Cat(Cat const &src) : Animal("Cat Parent"){
	std::cout << "Cat copy constructor is called" << std::endl;
	*this = src;
}

Cat::~Cat(void){
	std::cout << "Cat destructor is called" << std::endl;
	delete _brain;
}
Cat  &Cat::operator=(Cat const &rhs){
	if ( this != &rhs ){
		this->_type = rhs._type;
	}
	std::cout << "Cat copy assignement oprator  is called" << std::endl;
	return *this;
}

void	Cat::makeSound(void) const{
	std::cout << "miaowww !" << std::endl;
}