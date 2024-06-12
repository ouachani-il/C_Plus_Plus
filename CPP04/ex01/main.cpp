/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:33:35 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/12 16:22:49 by ilouacha         ###   ########.fr       */
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
	animals[N / 2 + k] = new Dog();
}

// Delete the allocated animals,
delete[] animals;
/*for (unsigned int k; k < N / 2; k++){
	animals;
	animals[N / 2 + k] = new Dog();
}*/

return 0;
}