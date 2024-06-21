/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:56:12 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/21 18:52:47 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
	_type = "ice";
	//std::cout << "Default Ice constructor is called" << std::endl;
	
}


Ice::Ice(Ice const &src) : AMateria("ice"){
	*this = src;
	//std::cout << " Copy Ice constructor is called" << std::endl;
	
}

Ice	&Ice::operator=(Ice const &src){
	//std::cout << "Copy assignement Ice constructor is called" << std::endl;
	if ( this != &src)
	{
		_type = src.getType();
	}
	return *this;
}
Ice::~Ice(void){	
	//std::cout << "Ice destructor is called" << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(){
	_type = type;
	//std::cout << _type << " Parametric Ice is created." << std::endl; 
}

/*std::string const	&Ice::getType() const{
	return (_type);
}*/

Ice*	Ice::clone() const{
	Ice	*copy = new Ice();
	return (copy);
	
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
	
}

