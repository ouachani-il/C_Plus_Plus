/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:44:05 by ilouacha          #+#    #+#             */
/*   Updated: 2024/08/01 15:59:35 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdio>
#include <fstream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
		std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(Intern const& src) {
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
}

Intern&	Intern::operator=(Intern const & rhs) {
	std::cout << "Intern Copy Assignement called" << std::endl;
	(void) rhs;
	return (*this);
}
Intern::~Intern(){
	std::cout << "Intern Destructor called" << std::endl;
}

static AForm*	makePresidentialForm(std::string targetName) {
	return new PresidentialPardonForm(targetName);
}

static AForm*	makeShrubberyForm(std::string targetName) {
	return new ShrubberyCreationForm(targetName);
}

static AForm*	makeRobotomyForm(std::string targetName) {
	return new RobotomyRequestForm(targetName);
}

AForm*	Intern::makeForm(std::string formName, std::string targetName){
	std::string	fType[3] = {"shrubbery", "robotomy request", "presidential"};
	
	AForm* (*formType[3]) (std::string) = {makePresidentialForm, makeRobotomyForm, makeShrubberyForm};
	int	i = 0;
	for (;i < 3; i++){
		if (formName == fType[i]){
			std::cout << "Intern creates" << formName << "form" << std::endl;
			return formType[i](targetName);
			break;
		}
	}
	throw Intern::formNotFound();
}
