/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:22:05 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/13 03:26:27 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
# define _CAT_HPP_

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal{
private:
	Cat(std::string type);
	
public:
	Cat(void);
	Cat(Cat const &src);
	Cat		&operator=(Cat const &rhs);
	virtual	~Cat(void);
	
	void	makeSound(void) const;
	
};

#endif