/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 06:43:47 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/13 02:40:23 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal {
protected:
	std::string _type;
	
public:
	Animal(void);
	Animal(Animal const &src);
	Animal			&operator=(Animal const &rhs);
	virtual			~Animal(void);
	
	virtual void	makeSound(void) const;
	
	std::string		getType(void) const;
	virtual Brain			*getBrain(void) const;
};
	//Animal(std::string type);
    /*
        Virtual destructor:
        A virtual destructor is used to free up the memory space allocated by 
        the derived class object or instance while deleting instances of the derived
        class using a base class pointer object. A base or parent class destructor
        use the virtual keyword that ensures both base class and the derived class 
        destructor will be called at run time, but it called the derived class first
        and then base class to release the space occupied by both destructors.

        Every destructor down gets called no matter what. virtual makes sure it
        starts at the top instead of the middle.

        Virtual destructors are useful when you might potentially delete an instance 
        of a derived class through a pointer to base class:
    */

#endif