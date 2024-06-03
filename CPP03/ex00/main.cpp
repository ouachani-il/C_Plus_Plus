/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:41:05 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/03 17:02:23 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

int main(void){
	ClapTrap	c("test1");
	ClapTrap	a("test2");

	// a attacks c
	c.attack("test1");
	a.beRepaired(5);
	c.takeDamage(5);
	a.attack("test1");
	c.takeDamage(5);
	c.attack("test2");
	//
}