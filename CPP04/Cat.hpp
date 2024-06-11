/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:22:05 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/11 07:31:30 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _Cat_HPP_
# define _Cat_HPP_

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal{
private:
	std::string _type;
	
public:
	Cat(void);
	Cat(std::string type);
	Cat(Cat const &src);
	Cat	&operator=(Cat const &rhs);
	virtual	~Cat(void);
	
};

#endif