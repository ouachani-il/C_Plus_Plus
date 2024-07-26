/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:33:35 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/23 21:26:46 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
const	AAnimal* j = new Dog();
const	AAnimal* i = new Cat();

delete	j;//should not create a leak
delete	i;

std::cout << std::endl;

unsigned int	N = 4;
const AAnimal*	animals[N];

for (unsigned int k = 0; k < N / 2; k++){
	animals[k] = new Dog();
	animals[N / 2 + k] = new Cat();
}
	std::cout << "here" << std::endl;
	Dog tanc;
	{
		Dog tmp = tanc;
		Dog free = Dog(tanc);
	}
   
   std::cout << std::endl;

// Delete the allocated animals,
for (unsigned int l = 0 ; l < N ; l++){
	delete animals[l];
}

return 0;
}

/*

interface is a class that contains only pure virtual functions and forces
the subclasses to implement them. It can't contain attibutes, but onlu virtual pure method.

Abstract class is a class that cann't be instanciated, it contains a method (virtual pure) 

A method is a virtual function member in a class.
*/