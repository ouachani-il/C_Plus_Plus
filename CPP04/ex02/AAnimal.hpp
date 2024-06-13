/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:42:24 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/13 02:49:21 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AANIMAL_HPP_
# define _AANIMAL_HPP_

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal {
protected:
	std::string _type;
	
public:
	AAnimal(void);
	AAnimal(AAnimal const &src);
	AAnimal			&operator=(AAnimal const &rhs);
	virtual			~AAnimal(void);
	
	virtual void	makeSound(void) const = 0;
	
	std::string		getType(void) const;
	virtual Brain			*getBrain(void) const;
};

#endif
