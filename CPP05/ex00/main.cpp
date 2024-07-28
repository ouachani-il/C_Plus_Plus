/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:00:19 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/28 20:49:31 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>


int main()
{
	try {
		Bureaucrat	Bur1("Bur1", 155);
	}
	catch(const std::exception& e) {
		std::cout << e.what() <<std::endl;
	}


	try {
		Bureaucrat Bur2("Bur2", 0);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat Bur3("Bur3", 150);
	Bureaucrat Bur4("Bur4", 1);
 
	
	std::cout<<Bur4;
	
	try{
		std::cout << "Increment B4" << std::endl;
		Bur4.incGrade();
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	std::cout<<Bur3;
	
	try {
		std::cout << "Decrement Bur3" << std::endl;
		Bur3.decGrade();
	}

	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

}
