/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:34:48 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/14 20:10:29 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ICharacter.hpp"
# include "Character.hpp"

static int	i = 0;

Character::Character(void){
	
}
Character::Character(std::string const &name){
	_name = name;
}
Character::Character(Character const &src){
	
}

Character::~Character(void){
	
}
Character	&Character::operator=(Character const &rhs){
	
}

std::string const & Character::getName() const{
	return (_name);
}

void Character::equip(AMateria* m) {
	if (i < 4)
		inv[i] = m;
	i++;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4){
		for (int k = idx; k < 4; k++){
			inv[k] = inv[k + 1];
		}
		i--;
	}
}
void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx <= i){
		target
	}
}

