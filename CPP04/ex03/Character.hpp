/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:19:55 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/20 11:05:48 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHARACTER_HPP_
# define _CHARACTER_HPP_

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"


class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria*	_inv[4];
	int	_iEquip;

public:
Character(void);
Character(std::string const &type);
Character(Character const &src);
virtual	~Character(void);
Character	&operator=(Character const &rhs);


std::string const & getName() const;
void equip(AMateria* m) ;
void unequip(int idx) ;
void use(int idx, ICharacter& target);
};

#endif