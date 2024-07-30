/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:44:16 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/30 18:22:07 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("request") {
		std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string t) : AForm("Robotomy", 72, 45), target(t){
	std::cout << "RobotomyRequestForm argument Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) {
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	std::cout << "RobotomyRequestForm Copy Assignement called" << std::endl;
	if (this != &rhs){
		this->target = rhs.target;
	}
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

std::string		RobotomyRequestForm::getTarget(void) const {
	return (this->target);
}

void RobotomyRequestForm::execute( Bureaucrat const & executor) const {
	if (!this->getSign()){
		throw FormNotSigned();
	}
	else if (executor.getGrade() > this->getMinExecGrade()){
		throw GradeTooLowException();
	}
	else if (this->getSign() && executor.getGrade() <= this->getMinExecGrade()){
		std::cout << "drillllllllllllllllllll... !" << std::endl;
		std::srand((long) this);
		//int	number = rand();
		if (std::rand() & 1){
			std::cout << this->getTarget() << " has been robotomized successfully !" << std::endl;
		}
		else {
			throw OperationFailed();
		}
	}
}