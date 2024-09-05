/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:13:19 by ilouacha          #+#    #+#             */
/*   Updated: 2024/08/01 17:51:07 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdio>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubery", 145, 137), target("request"){
		std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("Shrubery", 145, 137), target(t){
	std::cout << "ShrubberyCreationForm argument Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) {
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	std::cout << "ShrubberyCreationForm Copy Assignement called" << std::endl;
	if (this != &rhs){
		this->target = rhs.target;
	}
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

std::string		ShrubberyCreationForm::getTarget(void) const {
	return (this->target);
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor) const {
	if (!this->getSign()){
		throw FormNotSigned();
	}
	else if (executor.getGrade() > this->getMinExecGrade()){
		throw GradeTooLowException();
	}
	else if (this->getSign() && executor.getGrade() <= this->getMinExecGrade()){	
		std::string	name;
		name = this->target + "_shrubbery";
		std::ofstream file;
		file.open(name.c_str(),std::ios::out);
		if (!file) {
			throw fileNotOpened();
		}
		file << "        _-_" << std::endl;
		file << "   /~~       ~~\\ " << std::endl;
		file << "  /~~         ~~\\ " << std::endl;
		file << " {               }" << std::endl;
		file << "   \\  _-     -_  /" << std::endl;
		file << "   ~  \\ //  ~" << std::endl;
		file << "_- -   | | _- _" << std::endl;
		file << "_   -  | |   -_" << std::endl;
		file << "      // \\\\" << std::endl;
		file << std::endl;
		std::cout << "Executed by " << executor.getName()<<std::endl;
	}
}	