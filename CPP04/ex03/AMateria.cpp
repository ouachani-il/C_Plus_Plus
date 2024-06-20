/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:48:16 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/20 16:38:35 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria(void){
	_type = "Default materia";
	//std::cout << "Default AMateria constructor is called" << std::endl;
	
}


AMateria::AMateria(AMateria const &src){
	*this = src;
	//std::cout << " Copy AMateria constructor is called" << std::endl;
	
}

AMateria	&AMateria::operator=(AMateria const &src){
	//std::cout << "Copy assignement AMateria constructor is called" << std::endl;
	if (this != &src)
	{
		_type = src._type;
	}
	return *this;
}
AMateria::~AMateria(void){	
	//std::cout << "AMateria destructor is called" << std::endl;
}

AMateria::AMateria(std::string const & type) {
	_type = type;
	//std::cout << _type << " Parametric AMateria is created." << std::endl; 
}

std::string const	&AMateria::getType() const{
	return (_type);
}

/*AMateria*	AMateria::clone() const{
	std::cout << "Cloning AMateria." << std::endl; 
	
}*/

void AMateria::use(ICharacter& target){
	std::cout << "Materia: " << this->_type << " is used on " << target.getName() << "." << std::endl; 
	
}

/**************************Output on the ostream***********************/

std::ostream &	operator<<(std::ostream & o, AMateria const & i){
	o << i.getType();

	return o;
}


