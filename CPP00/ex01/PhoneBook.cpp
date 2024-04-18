/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:45:51 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/18 09:33:56 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void){
}

PhoneBook::~PhoneBook(void){
}

void	PhoneBook::addContact(void){
	static int	i;

	this->_contacts[i % 8].init();
	this->_contacts[i % 8].setIndex(i % 8);
	i++;
	// nombre de contacts cree dans le tableau
	if (i >= 8)
		this->_count = 8;
	else
		this->_count = i;
	return ;
}
void	PhoneBook::searchContact(void) const{
	int		sindex = -1;
	bool	nvalid = false;

	do
	{
		std::cout << "Please enter the index of the contact to display :" << std::flush;
		std::cin >> sindex;
		if (std::cin.good() && (sindex >= 0 && sindex < this->_count))
			nvalid = true;
		else{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "unvalid index !" << std::flush;
		}
	} while (!nvalid);
	this->_contacts[sindex].display();
	
	return ;
}

void	PhoneBook::printContacts(void) const{
	std::cout << "|";
	std::cout << std::setw(10) << "index" << std::flush;
	std::cout << "|";
	std::cout << std::setw(10) << "First Name" << std::flush;
	std::cout << "|";
	std::cout << std::setw(10) << "Last Name" << std::flush;
	std::cout << "|";
	std::cout << std::setw(10) << "Nickname" << std::flush;
	std::cout << "|";
	std::cout << std::endl;

	for (int i = 0; i < this->_count; i++){
		this->_contacts[i].viewContact();
	}
	return ;
}
void	PhoneBook::init(){
	std::cout << std::endl;
	std::cout << "Welcome to the Awesome PhoneBook !" << std::endl;
	std::cout << std::endl;
	std::cout << "-----------------How it works ?-----------------" << std::endl;
	std::cout << " ADD\t: add a contact to the Phonebook" << std::endl;
	std::cout << " Search\t: serarch a contact in the Phonebook" << std::endl;
	std::cout << " EXIT\t: add a contact to the Phonebook" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << std::endl;

}
