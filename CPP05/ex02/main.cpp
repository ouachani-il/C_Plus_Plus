/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:00:19 by ilouacha          #+#    #+#             */
/*   Updated: 2024/07/30 18:04:08 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	//// BUREAUCRAT
   std::cout << "*****Create Bureaucrat*****" << std::endl;
	Bureaucrat B1("Bureaucrat_1", 1);
	Bureaucrat B2("Bureaucrat_2", 149);
	std::cout << std::endl;

	//// SHRUBERRY FORM
	std::cout << "*****Create ShruberryForm*****" << std::endl;
	ShrubberyCreationForm s_form;
	std::cout << std::endl;

	std::cout << "*****Not Signed Form*****" << std::endl;
	
	B2.executeForm(s_form);
	std::cout << std::endl;
	std::cout << "*****Shruberry Grade Too Low*****" << std::endl;
	B1.signForm(s_form);
	B2.executeForm(s_form);
	std::cout << "*****Signed Form*****" << std::endl;
	B1.executeForm(s_form);
	std::cout << std::endl;

	//// ROBOTOMY FORM
	std::cout << "*****Create RobotomyForm*****" << std::endl;
	RobotomyRequestForm r_form;
	std::cout << std::endl;

	std::cout << "*****Not Signed Form*****" << std::endl;
  
	B2.executeForm(r_form);
	std::cout << std::endl;

	std::cout << "*****Signed Form (50/100 Success)*****" << std::endl;
	B1.signForm(r_form);

	std::cout << "*****Robotomy Grade Too Low*****" << std::endl;
	B2.executeForm(r_form);
	std::cout << "*****Signed Form (50/100 Success)*****" << std::endl;
	B1.executeForm(r_form);

	std::cout << std::endl;

	//// PRESIDENTION FORM
	std::cout << "*****Create PresidentialForm*****" << std::endl;
	PresidentialPardonForm p_form;
	std::cout << std::endl;

	std::cout << "*****Not Signed Form*****" << std::endl;
	B2.executeForm(p_form);
	std::cout << std::endl;

	B1.signForm(p_form);
	std::cout << "*****Presidential Grade Too Low*****" << std::endl;
	B2.executeForm(p_form);
	std::cout << "*****Signed Form*****" << std::endl;
	B1.executeForm(p_form);
	std::cout << std::endl;
	return (0);
}
