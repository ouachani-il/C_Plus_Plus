/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:16:17 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/25 16:04:06 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include <iostream>
#include "Zombie.hpp"

int	main(void){
	
	Zombie	z1 = Zombie("z1");
	Zombie*	z2 = newZombie("z2");

	z1.annonce();
	z2->annonce();
	randomChump("z3");
	std::cout << std::endl;
	delete z2;
	return 0;
}
