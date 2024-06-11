/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:23:58 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/11 07:32:13 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _Dog_HPP_
# define _Dog_HPP_

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal{
private:
	std::string _type;
	
public:
	Dog(void);
	Dog(std::string type);
	Dog(Dog const &src);
	Dog	&operator=(Dog const &rhs);
	virtual	~Dog(void);
	
};

#endif