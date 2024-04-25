/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:38:55 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/25 22:30:33 by ilham_oua        ###   ########.fr       */
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
		std::string _name;
		Weapon  _weap;
		
	public:
		HumanA(Weapon weap);
		~HumanA(void);
		void    attack(std::string type) const;
		void	_setWeapon(Weapon weap);
};
#endif