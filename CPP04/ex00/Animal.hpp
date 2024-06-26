/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 06:43:47 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/13 01:19:36 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

# include <iostream>
# include <string>

class Animal {
protected:
	std::string _type;
	Animal(std::string type);
	
public:
	Animal(void);
	Animal(Animal const &src);
	Animal	&operator=(Animal const &rhs);
	virtual			~Animal(void);
	
	virtual void	makeSound(void) const;
	
	std::string		getType(void) const;
	
};

#endif