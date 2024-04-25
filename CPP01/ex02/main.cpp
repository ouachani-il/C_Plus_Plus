/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:18:11 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/25 17:36:01 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void){
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR;
	std::string&	stringREF = str;
	
	stringPTR = &str;
	std::cout << "the string adress in memory \t:" << &str << std::endl;
	std::cout << "string pointer \t:" << stringPTR << std::endl;
	std::cout << "string reference \t:" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "the string content \t:" << str << std::endl;
	std::cout << "string pointer content \t:" << *stringPTR << std::endl;
	std::cout << "string reference content \t:" << stringREF << std::endl;

	return (0);
}