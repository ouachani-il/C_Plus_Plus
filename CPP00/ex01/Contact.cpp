/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:05:54 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/30 17:35:44 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

Contact::Contact(void){
}

Contact::~Contact(void){
}

/**
 * @brief This method is static (propoer to the Contact class) it prints the string 
 * within 10 caracters width., if the string's length is greater than 10 it is 
 * troncated to 9 caracter and the last one is replaced by .
 * 
 * @param str 
 */

void	Contact::_printStr(const std::string str){
	if (str.length() > 10)
		std::cout << str.substr(0,9) << '.' << std::flush;
	else
	{
		std::cout << std::setw(10);
		std::cout << str << std::flush;
	}
	return ;
}
/**
 * @brief this method prints the 4 first attributes of the contact respecting the given shape
 * 
 */
void	Contact::viewContact(void) const{
	if (this->_lastName.empty() || this->_firstName.empty() || this->_nickName.empty())
		return ;

	std::cout << "|";
	std::cout << std::setw(10) << this->_index << std::flush;
	std::cout << "|";
	this->_printStr(this->_firstName);
	std::cout << "|";
	this->_printStr(this->_lastName);
	std::cout << "|";
	this->_printStr(this->_nickName);
	std::cout << "|";
	std::cout << std::endl;
	return ;
}
/**
 * @brief This method is used to giev the search result if the contact is found
 * 
 */
void	Contact::display(void) const{
	if (this->_lastName.empty() || this->_firstName.empty() || this->_nickName.empty())
		return ;
	std::cout << std::endl;
	std::cout << "------contact number " << this->_index << "-------" << std::endl;
	std::cout << "First name \t:" << this->_firstName << std::endl;
	std::cout << "Last name \t:" << this->_lastName << std::endl;
	std::cout << "Nickname \t:" << this->_nickName << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	return ;
}

void	Contact::setIndex(int i){
	this->_index = i;
	return ;
}
bool	isAlphaNumerique(std::string str){
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isalnum(str[i]))
		return false;
	}
	return true;
}
/** 
 * un getteur generalisé pour tout type d'attribut de type string de la classe contact*/
std::string	Contact::_getStr(std::string str) const{
	
	std::string	input = "";
	bool		validStr = false;

	do
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof()){
			std::cout << "Pay attention ctrl + D is not accepted" << std::endl;
			validStr = true;
			//std::cout << "Invalid input, please try again" << std::endl;
		}
		if (std::cin.good() && !input.empty() && isAlphaNumerique(input))
			validStr = true;
		else{
			std::cin.clear();
			std::cout << "Invalid input, please try again" << std::endl;
		}
	} while (!validStr);
	return input;
}
/**
 * @brief initialize the contact with its different parameter when created
 * 
 */
void	Contact::init(void){
	std::cin.ignore();
	this->_firstName = this->_getStr("please enter your first Name\t:");
	this->_lastName = this->_getStr("please enter your last Name\t:");
	this->_nickName = this->_getStr("please enter your nickname\t:");
	this->_phoneNumber = this->_getStr("please enter your phone number\t:");
	this->_darkestSecret = this->_getStr("please enter your darkest secret\t:");
	//std::cout << std::endl;
}
