/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:38:55 by ilouacha          #+#    #+#             */
/*   Updated: 2024/05/01 10:36:38 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMAN_A_HPP_
# define _HUMAN_A_HPP_

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Weapon.hpp"

class HumanA{
	
	private:
		HumanA(void);
		std::string	_name;
		Weapon&		_weap;
		
	public:
		HumanA(std::string name, Weapon& weap);
		~HumanA(void);
		void	attack() const;
};
#endif