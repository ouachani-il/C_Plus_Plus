/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:22:05 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/11 16:46:06 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
# define _CAT_HPP_

# include <iostream>
# include <string>
# include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
private:
	std::string _type;
	Cat(std::string type);
	Brain*	_brain;
	
public:
	Cat(void);
	Cat(Cat const &src);
	Cat		&operator=(Cat const &rhs);
	virtual	~Cat(void);
	virtual void	makeSound(void) const;
	
};

#endif