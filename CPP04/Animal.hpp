/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 06:43:47 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/11 06:59:13 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

# include <iostream>
# include <string>

class Animal {
private:
	std::string _type;
	
public:
	Animal(void);
	Animal(std::string type);
	Animal(Animal const &src);
	Animal	&operator=(Animal const &rhs);
	virtual	~Animal(void);
	
};

#endif