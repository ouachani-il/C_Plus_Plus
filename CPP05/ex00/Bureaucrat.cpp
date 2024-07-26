/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:45:26 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/26 18:08:43 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs){
	if (this != &rhs){
		this->name = rhs.getName();
		this->grade = rhs.getGrade();
		
	}
	return *this;
}
Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

std::string		Bureaucrat::getName(){
	return (this->name);
}

int				Bureaucrat::getGrade(){
	return this->grade;
}

void	Bureaucrat::incGrade(){
	try{
		if (grade == 1)
		{
			throw "No increment is possible" ;
		}
	}
	catch(const std::out_of_range& e) {
		std::cout << "Out of range exception: " << e.what() << std::endl;
	}
		
}
void	Bureaucrat::decGrade(){
	try{
		if (grade == 150)
		{
			throw "No decrement is possible" ;
		}
	}
	catch(const std::out_of_range& e) {
		std::cout << "Out of range exception: " << e.what() << std::endl;
	}
		
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade "<<bureaucrat.getGrade()<<std::endl;
    return os;
}
