/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:22:35 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/03 17:06:19 by ilouacha         ###   ########.fr       */
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
		std::string		_getStr( const std::string& str);
		//printList();
	private :
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int			_index;
	
		std::string		_getNbr(std::string str) const;
		static void		_printStr(const std::string str);
};

#endif