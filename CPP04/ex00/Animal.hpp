/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 06:43:47 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/11 12:49:32 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

# include <iostream>
# include <string>

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
	std::string		getType(void) const;
	
};

#endif