/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:43:50 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/18 08:41:55 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

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
		void	addContact(void);
		void	searchContact(void) const;
		void	init(void);
		void	printContacts(void) const;
	private :
		int		_count;
		Contact	_contacts[8];
};

#endif
