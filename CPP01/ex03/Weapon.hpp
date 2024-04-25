/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:04:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/25 22:23:56 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_HPP_
# define _WEAPON_HPP_

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Weapon{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		Weapon::~Weapon(void);
		void    _setType(std::string type);
		std::string _getType(void) const;
};
#endif