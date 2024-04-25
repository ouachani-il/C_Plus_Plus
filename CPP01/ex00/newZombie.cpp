/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZambie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:26:32 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/25 15:20:25 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie*	newZombie(std::string name){
	Zombie*	z = new Zombie(name);
	return (z);
}
