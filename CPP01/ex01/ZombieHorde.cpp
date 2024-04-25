/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:17:51 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/25 17:14:05 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief a functionn using std::to_string routine
 * 
 */
/*Zombie* zombieHorde( int N, std::string name ){
	Zombie*	horde = new Zombie[N];
	
	for(int i; i = 0, i < N; i++)
	{
		horde[i] = Zombie(name + std::to_string(i));
		horde[i].annonce();
	}
	return (horde);
}*/

/**
 * @brief a function using sstream to concatenate the num with the table index
 * 
 * @param N 
 * @param name 
 * @return Zombie* 
 */
Zombie* zombieHorde( int N, std::string name ){
	Zombie*	horde = new Zombie[N];
	
	for(int i = 0; i < N; i++)
	{
		std::ostringstream oss;
		oss << name << "(" << i << ")";
		horde[i]._setName(oss.str());
	}
	return (horde);
}

/**
 * @brief this fuunction uses the setname function without changing the name
 * 
 * @param N 
 * @param name 
 * @return Zombie* 
 */
/*Zombie* zombieHorde( int N, std::string name ){
	Zombie*	horde = new Zombie[N];
	
	for(int i = 0; i < N; i++)
	{
		horde[i]._setName(name);
	}
	return (horde);
}*/