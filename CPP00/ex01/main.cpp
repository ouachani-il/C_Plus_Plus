/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:30:37 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/16 00:11:41 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <cstring>
#include <iostream>

int main(void){
	PhoneBook   phoneBook;
	std::string cmd = "";

	
	while (cmd != "EXIT")
	{
		switch (cmd)
		{
		case "ADD":
			phoneBook.Add();
			break;
		case "SEARCH":
			phoneBook.Search();
			break;
		case "EXIT":
			exit();
		break;
	
	default:
		break;
	}
	}
	return 0;
}


