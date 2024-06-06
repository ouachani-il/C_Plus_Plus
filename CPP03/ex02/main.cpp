/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:58:59 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/06 12:05:09 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	bob = ClapTrap("Bob");

	bob.attack("a worm");
	bob.takeDamage(9);

	FragTrap	j = FragTrap("John");

	j.attack("a human");
	j.highFivesGuys();
	j.beRepaired(5);
}


