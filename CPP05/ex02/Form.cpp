/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:45:51 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/29 19:47:27 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdio>

AForm::AForm() : 
		_name("Default"), 
		_signed(0), 
		minSignGrade(1), 
		minExecGrade(150) {
		std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const std::string n, const int minSG, const int minEG) : 
		_name(n), 
		_signed(0), 
		minSignGrade(minSG), 
		minExecGrade(minEG) {
	// assign the min grade to sign
	if (minSG < 1)
		throw AForm::GradeTooHighException();
	else if (minSG > 150)
		throw AForm::GradeTooLowException();

	// assign the min grade to exec
	if (minEG < 1)
		throw AForm::GradeTooHighException();
	else if (minEG > 150)
		throw AForm::GradeTooLowException();

}

AForm::AForm(AForm const & src) 
				: _name(src._name), 
				_signed(src._signed), 
				minSignGrade(src.minSignGrade), 
				minExecGrade(src.minExecGrade) {
	std::cout << "AForm Copy Constructor called" << std::endl;
	*this = src;
}

AForm&	AForm::operator=(AForm const & rhs) {
	std::cout << "AForm Copy Assignement called" << std::endl;
	if (this != &rhs){
		this->_signed = rhs.getSign();
	}
	return (*this);
}
AForm::~AForm(){
	std::cout << "AForm Destructor called" << std::endl;
}

std::string		AForm::getName() const {
	return (this->_name);
}
int		AForm::getMinSignGrade() const {
	return (this->minSignGrade);
}
int		AForm::getMinExecGrade() const{
	return (this->minExecGrade);
}

bool			AForm::getSign() const{
	return (this->_signed);
}
void	AForm::beSigned(Bureaucrat const& B){
	if(!(this->_signed) && (B.getGrade() > this->getMinSignGrade()))
		throw AForm::GradeTooLowException();
	else if (!(this->_signed) && (B.getGrade() <= this->getMinSignGrade()))
		this->_signed = 1;
}


std::ostream&	operator<<(std::ostream& os, const AForm& f){
	os << "Form : " << f.getName() << (f.getSign() == 0 ? " isn't signed." : " is signed.") 
	<< " Grade required: "
	<< f.getMinSignGrade() 
	<< ", and grade for exec "
	<< f.getMinExecGrade()
	<<". signed = "
	<< f.getSign()
	<< std::endl;
	return os;
}
