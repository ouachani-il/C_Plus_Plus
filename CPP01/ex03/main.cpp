/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:36:46 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/26 17:03:56 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main(void){
	{
		Weapon  club = Weapon("crud spiked club");
		HumanA  bob("Bob", club);
		bob.attack();
		club._setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB  jim("Jim");
		jim._setWeapon(club);
		jim.attack();
		club._setType("some other type of club");
		jim.attack();
	}
	return 0;
}