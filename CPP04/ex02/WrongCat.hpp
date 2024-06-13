/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:02:41 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/11 13:13:32 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONGCAT_HPP_
# define _WRONGCAT_HPP_

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
private:
	std::string _type;
	WrongCat(std::string type);
	
public:
	WrongCat(void);
	WrongCat(WrongCat const &src);
	WrongCat		&operator=(WrongCat const &rhs);
	virtual	~WrongCat(void);
	void	makeSound(void) const;
	
};

#endif