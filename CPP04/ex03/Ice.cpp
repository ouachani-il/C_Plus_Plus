/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:56:12 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/13 15:05:09 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria(){
	_type = "ice";
	std::cout << "Default Ice constructor is called" << std::endl;
	
}


Ice::Ice(Ice const &src) : AMateria(){
	*this = src;
	std::cout << " Copy Ice constructor is called" << std::endl;
	
}

Ice	&Ice::operator=(Ice const &src){
	std::cout << "Copy assignement Ice constructor is called" << std::endl;
	if ( this != &src){
		_type = src._type;
	}
	
}
Ice::~Ice(void){	
	std::cout << "Ice destructor is called" << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(){
	_type = type;
	std::cout << _type << " Parametric Ice is created." << std::endl; 
}

/*std::string const	&Ice::getType() const{
	return (_type);
}*/

Ice*	Ice::clone() const{
	std::cout << "Cloning Materia." << std::endl; 
	
}

void Ice::use(ICharacter& target){
	std::cout << "use ICharater called." << std::endl; 
	
}
