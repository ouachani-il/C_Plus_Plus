/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:22:35 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/17 18:17:38 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>


class	Contact{
	public :
		Contact();
		~Contact(void);
		
		void	display(void) const;
		void	viewContact(void) const;
		void	setIndex(int i);
		void	init(void);
		//printList();
	private :
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int			_index;
	
		std::string		_getStr(std::string str) const;
		static void		_printStr(const std::string str);
};

#endif