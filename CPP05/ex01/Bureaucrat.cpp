/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:45:26 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/29 15:20:11 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
		std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string n, int g) : name(n) {
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	if (g > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = g;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src): name(src.getName()) 
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs) {
	std::cout << "Bureaucrat Copy Assignement called" << std::endl;
	if (this != &rhs){
		this->grade = rhs.getGrade();
		
	}
	return *this;
}
Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

const std::string		Bureaucrat::getName() const {
	return (this->name);
}

int				Bureaucrat::getGrade() const {
	return this->grade;
}

void	Bureaucrat::incGrade(){
	if (grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		std::cout << "INCREMENT" << std::endl;
		this->grade--;
		std::cout << "grade : " << this->grade << std::endl;
	}

}
void	Bureaucrat::decGrade() {
	if (grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else{
		std::cout<< "DECREMENT" << std::endl;
		this->grade ++;
		std::cout << "grade : " << this->grade << std::endl;
	}
	
		
}

void		Bureaucrat::signForm(Form& f){
	try {
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception& e){
		std::cout << this->name << " coudn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
	
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade "<< bureaucrat.getGrade() << std::endl;
	return os;
}
