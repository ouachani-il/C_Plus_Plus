/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:04:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/04/29 17:37:08 by ilouacha         ###   ########.fr       */
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
		~Weapon(void);
		void	_setType(std::string type);
		const std::string& _getType(void) const;
};
#endif