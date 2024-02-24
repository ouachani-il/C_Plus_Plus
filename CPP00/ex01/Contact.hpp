/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:22:35 by ilouacha          #+#    #+#             */
/*   Updated: 2024/02/24 20:35:08 by ilouacha         ###   ########.fr       */
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
				std::string darkest_secret
				int			index);
		_display();
		_print();
		~Contact(void);
		std::string	_get_first(){
			return this->_first_name;
		}
	private :
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		int			_index;
	
};

#endif