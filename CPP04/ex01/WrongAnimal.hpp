/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:16:35 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/11 13:31:08 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONGANIMAL_HPP_
# define _WRONGANIMAL_HPP_

# include <iostream>
# include <string>


class WrongAnimal {
protected:
	std::string _type;
	WrongAnimal(std::string type);
	
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &src);
	WrongAnimal	&operator=(WrongAnimal const &rhs);
	virtual			~WrongAnimal(void);
	void			makeSound(void) const;
	std::string		getType(void) const;
	
};

#endif