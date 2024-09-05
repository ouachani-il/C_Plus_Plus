/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:00:19 by ilouacha          #+#    #+#             */
/*   Updated: 2024/08/01 17:30:44 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>


int main()
{
	// try {
	// 	Bureaucrat	Bur1("Bur1", 155);
	// }
	// catch(const std::exception& e) {
	// 	std::cout << e.what() <<std::endl;
	// }


	// try {
	// 	Bureaucrat Bur2("Bur2", 0);
	// }
	// catch(const std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// std::cout << std::endl;

	// Bureaucrat Bur3("Bur3", 150);
	// Bureaucrat Bur4("Bur4", 1);
 
	
	// std::cout<<Bur4;
	
	// try{
	// 	std::cout << "Increment B4" << std::endl;
	// 	Bur4.incGrade();
	// }
	// catch(const std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	
	// std::cout << std::endl;
	
	// std::cout<<Bur3;
	
	// try {
	// 	std::cout << "Decrement Bur3" << std::endl;
	// 	Bur3.decGrade();
	// }

	// catch(const std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// std::cout << std::endl;

	//Testing ex01

	Form	form1("Form 1", 7, 12);
	std::cout <<form1;
	
	//incorrect
	std::cout << "//// Not Signed///////" << std::endl;
	Bureaucrat	B("B", 150);
	B.signForm(form1);
	std::cout << std::endl;

	//correct
	std::cout << "//// Signed///////" << std::endl;
	Bureaucrat	Bc("Bc", 5);
	Bc.signForm(form1);
	std::cout << std::endl;

	//affichage form

	std::cout <<form1;
	
	//Form copy by constructor
	std::cout << "Form copy by constructor" << std::endl;
	Form	form2(form1);
	std::cout <<form2;

	// Form copy by assignement
	std::cout << "Form copy by assignement" << std::endl;
	Form	form3 = form2;
	
	std::cout << std::endl;
	// surcharge << form
	std::cout <<form3;
	
}
