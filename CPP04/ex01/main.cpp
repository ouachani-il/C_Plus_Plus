/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:33:35 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/12 11:44:14 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
const	Animal* j = new Dog();
const	Animal* i = new Cat();
delete	j;//should not create a leak
delete	i;
unsigned int	N = 10;
Animal	*animals[N];

for (unsigned int k = 0; k < N / 2; k++){
	animals[k] = new Cat();
	animals[N / 2 + k + 1] = new Dog();
}

// Delete the allocated animals,
delete[] animals;
/*for (unsigned int k; k < N / 2; k++){
	animals;
	animals[N / 2 + k] = new Dog();
}*/

return 0;
}