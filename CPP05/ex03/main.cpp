/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:00:09 by ilouacha          #+#    #+#             */
/*   Updated: 2024/08/01 17:57:17 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	// INTERN CREATE
	std::cout << "-----Create Intern-----" << std::endl;
	Intern someRandomIntern;

	// AFORM*
	AForm* rrf = NULL;
	AForm* rrf1 = NULL;
	AForm* rrf2 = NULL;
	AForm* rrf_e = NULL;

	// MAKEAFORM  
	try
	{
		std::cout << "------ROBOTOMY-----" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "robot");
		std::cout << "-----PRESIDENTIAL-----" << std::endl;
		rrf1 = someRandomIntern.makeForm("presidential", "president");
		std::cout << "-----SHRUBBERY-----" << std::endl;
		rrf2 = someRandomIntern.makeForm("shrubbery", "Shrub");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	std::cout << "-----ERROR FORM-----" << std::endl;
	try
	{
		rrf_e = someRandomIntern.makeForm("error form", "Error");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "-----FREE/DESTRUCTOR-----" << std::endl;

	delete rrf;
	delete rrf1;
	delete rrf2;
	delete rrf_e;
	
	return (0);
}
