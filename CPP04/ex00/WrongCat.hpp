/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:02:41 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/13 02:55:37 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONGCAT_HPP_
# define _WRONGCAT_HPP_

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
private:
	WrongCat(std::string type);
	
public:
	WrongCat(void);
	WrongCat(WrongCat const &src);
	WrongCat		&operator=(WrongCat const &rhs);
	virtual	~WrongCat(void);
	void	makeSound(void) const;
	
};

#endif