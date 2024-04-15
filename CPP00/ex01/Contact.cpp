/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:05:54 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/16 00:41:06 by ilham_oua        ###   ########.fr       */
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
        int _ind) : _first_name(first_name),
		_last_name(last_name),
		_nickname(nickname),
		_phone_number(phone_number),
		_darkest_secret(darkest_secret),
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
	print_string(_index);
	std::cout<<'|';
	print_string(_first_name);
	strd::cout<<'|';
	
}

void	Contact::_displayContact(){
	std::cout<<_first_name << std::endl;
	
}


