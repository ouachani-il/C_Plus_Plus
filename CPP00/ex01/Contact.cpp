/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:05:54 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/16 00:56:37 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
}

Contact::Contact(std::string first_name,
		std::string last_name,
		std::string nickname,
		std::string	phone_number,
		std::string darkest_secret,
        int _ind) : _firstName(first_name),
		_lastName(last_name),
		_nickName(nickname),
		_phoneNumber(phone_number),
		_darkestSecret(darkest_secret),
        _index(_ind);

Contact::~Contact(){
}

static void print_string(const std::string &str){
	if (str.length() > 10)
		std::cout<<str.substr(0,9)<<'.';
	else
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
}

void	Contact::_printList(){
	std::cout<<'|';
	print_string((int)(this->_index));
	std::cout<<'|';
	print_string(this->_firstName);
	std::cout<<'|';
	
}

void	Contact::_displayContact(){
	std::cout<<_first_name << std::endl;
	
}


