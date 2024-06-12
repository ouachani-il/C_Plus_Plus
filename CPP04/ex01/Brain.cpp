/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:29:19 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/12 16:11:00 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain default constructor is called" << std::endl;
	for (unsigned int i = 0; i < 100; i++ ){
		*ideas[i] = "Default";
	}	
}

Brain::Brain(std::string str) {
	std::cout << "Brain parametric constructor is called" << std::endl;
	for (unsigned int i = 0; i < 100; i++ ){
		*ideas[i] = str;
	}	
}
Brain::Brain(Brain const &src){
	std::cout << "Brain copy constructor is called" << std::endl;
	*this = src;
}

Brain::~Brain(void){
	std::cout << "Brain destructor is called" << std::endl;
}
Brain  &Brain::operator=(Brain const &rhs){
	if (this != &rhs){
		for (unsigned int i = 0; i < 100; i++ ){
			ideas[i] = rhs.ideas[i];
		}
	}
	std::cout << "Brain copy assignement oprator  is called" << std::endl;
	return *this;
}

std::string	Brain::getIdeas(unsigned int i) const{
	return ( *ideas[i]);
}

void		Brain::setIdeas(std::string str, unsigned int i){
	*ideas[i] = str;
}


