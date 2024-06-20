/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:16:29 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/20 16:37:39 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
Cure::Cure(void) : AMateria("Cure"){
	_type = "cure";
	//std::cout << "Default Cure constructor is called" << std::endl;
	
}


Cure::Cure(Cure const &src) : AMateria("Cure"){
	*this = src;
	//std::cout << " Copy Cure constructor is called" << std::endl;
	
}

Cure	&Cure::operator=(Cure const &src){
	//std::cout << "Copy assignement Cure constructor is called" << std::endl;
	if ( this != &src){
		_type = src._type;
	}
	return *this;
}
Cure::~Cure(void){	
	//std::cout << "Cure destructor is called" << std::endl;
}


/*std::string const	&Cure::getType() const{
	return (_type);
}*/

Cure*	Cure::clone() const{
	//std::cout << "Cloning Materia." << std::endl; 
	Cure	* copy = new Cure(*this);
	return (copy);
	
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() <<"'s wounds *" << std::endl; 
	
}


