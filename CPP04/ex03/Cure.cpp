/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:16:29 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/17 16:18:45 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
Cure::Cure(void) : AMateria("Cure"){
	_type = "cure";
	std::cout << "Default Cure constructor is called" << std::endl;
	
}


Cure::Cure(Cure const &src) : AMateria("Cure"){
	*this = src;
	std::cout << " Copy Cure constructor is called" << std::endl;
	
}

Cure	&Cure::operator=(Cure const &src){
	std::cout << "Copy assignement Cure constructor is called" << std::endl;
	if ( this != &src){
		_type = src._type;
	}
	
}
Cure::~Cure(void){	
	std::cout << "Cure destructor is called" << std::endl;
}


Cure::Cure(std::string const & type) : AMateria(){
	_type = type;
	std::cout << _type << " parametric Cure is created." << std::endl; 
}


/*std::string const	&Cure::getType() const{
	return (_type);
}*/

Cure*	Cure::clone() const{
	std::cout << "Cloning Materia." << std::endl; 
	Cure	* copy = new Cure(this->_type);
	return (copy);
	
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() <<"'s wounds *" << std::endl; 
	
}
