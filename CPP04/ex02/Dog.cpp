/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:25:00 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/13 03:22:24 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) : AAnimal(){
    _type = "Dog";
	_brain = new Brain();
	std::cout << "Animal default constructor is called" << std::endl;
}

/*Dog::Dog(std::string type) : Animal(type + " Parent") { 
    _type = type; 
	_brain = new Brain();  
	std::cout << "Dog parametric constructor is called" << std::endl;
}*/
Dog::Dog(Dog const &src): AAnimal(){
	std::cout << "Dog copy constructor is called" << std::endl;
	*this = src;
}

Dog::~Dog(void){
	std::cout << "Dog destructor is called" << std::endl;
	delete _brain;
}
Dog  &Dog::operator=(Dog const &rhs){
	if ( this != &rhs ){
		this->_type = rhs._type;
		_brain = new Brain(*rhs._brain);
	}
	std::cout << "Dog copy assignement oprator  is called" << std::endl;
	return *this;
}

void	Dog::makeSound(void) const{
	std::cout << "habhabhab !!" << std::endl;
}

Brain	*Dog::getBrain() const{
	return _brain ;
}