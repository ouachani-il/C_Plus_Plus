/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:33:35 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/13 04:26:58 by ilham_oua        ###   ########.fr       */
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

   std::cout << std::endl;

unsigned int	N = 4;
Animal*	animals[N];

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
/*int main( void )
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    Dog basic;
    {
        Dog tmp = basic;
    }

    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }

    return 0;
}*/

/* virtual means the the linkage will be dynamic not static 
    Explaination:
    At the beginning, we had a statis relution of the function calls, It means that
    during the compilation, (the compiler) we already will know which function to call.
    and for this we use the type of the variable.
    The only way for the compiler to know the behavior of my object is by knowing its type.
    and we marked it as a Character type. and the compiler will assume that its a Character.
    Therefore, it uses the Character version of the function.
    It was a static link! means that during the compilation is determined it won't change later.
    However, during the compilation let assume that we don't want it as a Warriror, but as a Wizard.
    it may point on a Warrior once and on the Wizard once based on what the user input.
    Thanks to the virtual, the resulotion of the function call wil be dynamic. and it will be
    decided at runtime.

    When we call the member function, during the execution becauese it's a function with 
    a dynamic link, it will look for the actual type of the object. It will walk 
    through the inheritance tree to find the actual type.

    A virtual member function is called a method.
    The definition of a method is a member function which resulotion will be dynamic.

Rules of Virtual Function:

    - Virtual functions must be members of some class.
    - Virtual functions cannot be static members.
    - They are accessed through object pointers.
    - They can be a friend of another class.
    - A virtual function must be defined in the base class, even though it is not used.
    - The prototypes of a virtual function of the base class and all the derived classes 
        must be identical. If the two functions with the same name but different prototypes,
        C++ will consider them as the overloaded functions.
    - We cannot have a virtual constructor, but we can have a virtual destructor

*/
