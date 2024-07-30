/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:45:22 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/30 16:30:27 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), target("request"){
		std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string t) : AForm("Presidential", 25, 5), target(t){
	std::cout << "PresidentialPardonForm argument Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) {
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	std::cout << "PresidentialPardonForm Copy Assignement called" << std::endl;
	if (this != &rhs){
		this->target = rhs.target;
	}
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

std::string		PresidentialPardonForm::getTarget(void) const {
	return (this->target);
}

void PresidentialPardonForm::execute( Bureaucrat const & executor) const {
	if (!this->getSign()){
		throw FormNotSigned();
	}
	else if (executor.getGrade() > this->getMinExecGrade()){
		throw GradeTooLowException();
	}
	else if (this->getSign() && executor.getGrade() <= this->getMinExecGrade()){
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}