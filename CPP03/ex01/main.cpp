/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:41:44 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/06 11:15:48 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
int main(void){
	ClapTrap	c("test1");
	ScavTrap	a("test2");

	// a attacks c
	c.attack("test2");
	a.beRepaired(5);
	c.takeDamage(5);
	a.attack("test1");
	c.takeDamage(5);
	c.attack("test2");
	c.attack("test2");
	a.beRepaired(5);
	a.guardGate();
	a.guardGate();
	//
}
/**
 * @brief hier we have to define a class that heritate from the ClapTrap class, 
 * we have to define a function that masks the attack ClapTrap function and a 
 * new member function.
 * the private attributes of ClapTrap become protected to be accecced by the heritating class
 * 
 * ScavTrap::attack() : public Claptrap
 * Scvptrap::ScavTrap(...) : public ClapTrap car il doit appeler le constructeur de ClapTrap 
 * avant ScavTrap puisque les parametres ne sont pas redefinis dans scavtrap
 */