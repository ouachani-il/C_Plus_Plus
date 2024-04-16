/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:22:35 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/16 00:56:58 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip> 


class   Contact{
    public :
		Contact();
		Contact(std::string first_name,
				std::string last_name,
				std::string nickname,
				std::string	phone_number,
				std::string darkest_secret,
				int			index);
		_displayContact();
		_printList();
		~Contact(void);
		std::string	_get_first(){
			return this->_firstName;
		}
	private :
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int			_index;
	
};

#endif