/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:43:50 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/02/23 21:51:14 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_H

class   PhoneBook{
	public :
		PhoneBook(void);
		~PhoneBook(void);
		Add();
		Search();
		Delete();
	private :
		Contact old_contact;
		Contact	tab_contact[8];
    
};


class   Contact{
    public :
		Contact();
		~Contact(void);
	private :
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		int			_phone_number;
		std::string	_darkest_secret
	
};

#endif