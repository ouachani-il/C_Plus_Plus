/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:43:50 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/16 00:38:18 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <limits>
#include <stdlib.h> /* atoi */

#include "Contact.hpp"

class   PhoneBook{
	public :
		PhoneBook(void);
		~PhoneBook(void);
		Add();
		Search();
	private :
		Contact old_contact;
		Contact	_contacts[8];
    
};

#endif

#endif
