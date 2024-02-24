/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:43:50 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/02/24 20:35:37 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <limits>
#include <stdlib.h> /* atoi */

class   PhoneBook{
	public :
		PhoneBook(void);
		~PhoneBook(void);
		Add();
		Search();
		Delete();
	private :
		Contact old_contact;
		Contact	_contacts[8];
    
};


#endif