/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 06:43:47 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/12 16:23:13 by ilouacha         ###   ########.fr       */
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
	Animal(std::string type);
	Animal(Animal const &src);
	Animal	&operator=(Animal const &rhs);
	virtual			~Animal(void);
	
	virtual void	makeSound(void) const;
	
	virtual std::string		getType(void) const;
	virtual Brain			*getBrain(void) const;
};

#endif