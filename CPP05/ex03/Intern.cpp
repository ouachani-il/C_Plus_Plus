/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:44:05 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/30 20:49:20 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdio>
#include <fstream>

Intern::Intern() {
		std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(std::string type, std::string targetName) {
	std::cout << "Intern argument Constructor called" << std::endl;
}

Intern::Intern(Intern const& src) {
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
}

Intern&	Intern::operator=(Intern const & rhs) {
	std::cout << "Intern Copy Assignement called" << std::endl;
	if (this != &rhs){
		this->target = rhs.target;
	}
	return (*this);
}
Intern::~Intern(){
	std::cout << "Intern Destructor called" << std::endl;
}

AForm*	Intern::makeForm(std::string nform, std::string targetName){
	
}
