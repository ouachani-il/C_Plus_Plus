/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 04:30:01 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/06/20 15:29:36 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AMATERIA_HPP_
# define _AMATERIA_HPP_

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
/*private:
	AMateria();*/
	
protected:
	std::string	_type;
	
public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	virtual	~AMateria(void);
	AMateria	&operator=(AMateria const &rhs);
	
	std::string const 	&getType() const; //Returns the materia type
	virtual AMateria* 	clone() const = 0;
	virtual void 		use(ICharacter& target);
};

std::ostream	&operator<<(std::ostream &o, AMateria const &i);

#endif