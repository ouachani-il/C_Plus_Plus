/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:23:58 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/11 16:55:07 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
# define _DOG_HPP_

# include <iostream>
# include <string>
# include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
private:
	std::string _type;
	Dog(std::string type);
	Brain*	_brain;
	
public:
	Dog(void);
	Dog(Dog const &src);
	Dog		&operator=(Dog const &rhs);
	virtual	~Dog(void);
	virtual void	makeSound(void) const;
	
};

#endif