/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:19:00 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/29 16:53:57 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdio>

Form::Form() : 
		_name("Default"), 
		_signed(0), 
		minSignGrade(1), 
		minExecGrade(150) {
		std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string n, const int minSG, const int minEG) : 
		_name(n), 
		_signed(0), 
		minSignGrade(minSG), 
		minExecGrade(minEG) {
	// assign the min grade to sign
	if (minSG < 1)
		throw Form::GradeTooHighException();
	else if (minSG > 150)
		throw Form::GradeTooLowException();

	// assign the min grade to exec
	if (minEG < 1)
		throw Form::GradeTooHighException();
	else if (minEG > 150)
		throw Form::GradeTooLowException();

}

Form::Form(Form const & src) 
				: _name(src._name), 
				_signed(src._signed), 
				minSignGrade(src.minSignGrade), 
				minExecGrade(src.minExecGrade) {
	std::cout << "Form Copy Constructor called" << std::endl;
	*this = src;
}

Form&	Form::operator=(Form const & rhs) {
	std::cout << "Form Copy Assignement called" << std::endl;
	if (this != &rhs){
		this->_signed = rhs.getSign();
	}
	return (*this);
}
Form::~Form(){
	std::cout << "Form Destructor called" << std::endl;
}

std::string		Form::getName() const {
	return (this->_name);
}
int		Form::getMinSignGrade() const {
	return (this->minSignGrade);
}
int		Form::getMinExecGrade() const{
	return (this->minExecGrade);
}

bool			Form::getSign() const{
	return (this->_signed);
}
void	Form::beSigned(Bureaucrat const& B){
	if(!(this->_signed) && (B.getGrade() > this->getMinSignGrade()))
		throw Form::GradeTooLowException();
	else if (!(this->_signed) && (B.getGrade() <= this->getMinSignGrade()))
		this->_signed = 1;
}


std::ostream&	operator<<(std::ostream& os, const Form& f){
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

