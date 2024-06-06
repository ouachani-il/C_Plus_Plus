/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:58:59 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/06 23:57:50 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	bob = ClapTrap("Bob");

	bob.attack("a worm");
	bob.takeDamage(9);

	FragTrap	j = FragTrap("John");

	j.attack("a human");
	j.highFivesGuys();
	j.beRepaired(5);

	DiamondTrap	diamond = DiamondTrap("derived");
	
	diamond.whoAmI();
	diamond.attack("anyone");
	diamond.beRepaired(5);
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.takeDamage(10);
	return 0;
}


