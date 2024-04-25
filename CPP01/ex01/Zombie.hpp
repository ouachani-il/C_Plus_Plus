/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:13:00 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/25 17:05:29 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _Zombie_HPP_
# define _Zombie_HPP_

#include <string>
#include <iostream>
#include<string>
#include <sstream>

class Zombie{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	annonce(void) const;
		std::string	_getName(void) const;
		void	_setName(std::string const name);
		
	private:
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif