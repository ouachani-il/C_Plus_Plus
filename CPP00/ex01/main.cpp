/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:30:37 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/05/03 15:22:06 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
// #include <string>
// #include <cstring>
// #include <iostream>
#include <csignal>

void	signal_handler(int signal)
{
	std::cout << " Exiting due to Ctrl+C " << std::endl;
	_exit(signal);
}

int main(void){
    signal(SIGINT, signal_handler);
	PhoneBook	phoneBook;
	std::string	cmd = "";

	phoneBook.init();
	
	while (cmd != "EXIT")
	{
		if(std::cin.eof())
			break;
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


