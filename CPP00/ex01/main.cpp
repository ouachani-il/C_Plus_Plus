/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:30:37 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/17 18:27:07 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <cstring>
#include <iostream>

int main(void){
	PhoneBook	phoneBook;
	std::string	cmd = "";

	phoneBook.init();
	while (cmd != "EXIT")
	{
		if (cmd == "ADD")
		{
			phoneBook.addContact();
		}
		else if (cmd == "SEARCH")
		{
			phoneBook.printContacts();
			phoneBook.searchContact();
		}

		std::cout << ">" << std::flush;
		std::cin >> cmd;
	}
	return 0;
}


