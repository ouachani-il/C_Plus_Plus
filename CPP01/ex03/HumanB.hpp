/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:43 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/29 17:34:04 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMAN_B_HPP_
# define _HUMAN_B_HPP_

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Weapon.hpp"

class HumanB{
	
	private:
		std::string _name;
		Weapon*	_weap;
		
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void) const;
		void	_setWeapon(Weapon& weap);
};
#endif
