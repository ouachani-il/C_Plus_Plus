/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:33:35 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/11 14:33:36 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

const WrongAnimal* meta2 = new WrongAnimal();
const WrongAnimal* k = new WrongCat();
std::cout << k->getType() << " " << std::endl;

meta2->makeSound();
k->makeSound(); //won't output the cat sound ! since it is static !

delete meta;
delete i;
delete j;

return 0;
}