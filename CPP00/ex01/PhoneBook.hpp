/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:43:50 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/16 00:20:22 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_H

#include "Contact.hpp"

class   PhoneBook{
	public :
		PhoneBook(void);
		~PhoneBook(void);
		Add();
		Search();
		Delete();
	private :
		Contact _old_contact;
		Contact	_tab_contact[8];
    
};

#endif

PhoneBook::Add()