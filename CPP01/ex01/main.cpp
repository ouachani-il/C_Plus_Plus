/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:16:17 by ilouacha          #+#    #+#             */
/*   Updated: 2024/04/25 17:15:39 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 5

int	main(void){
	
	Zombie*	horde = zombieHorde(5, "Zombie ");

	
	for(int i = 0; i < N; i++){
		horde[i].annonce();
	}
	std::cout << std::endl;
	delete[] horde;
	return 0;
}
