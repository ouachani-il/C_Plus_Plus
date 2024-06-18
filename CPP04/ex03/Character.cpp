/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:34:48 by ilouacha          #+#    #+#             */
/*   Updated: 2024/06/18 15:06:19 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ICharacter.hpp"
# include "Character.hpp"

static int	i = 0;

Character::Character(void){
	_name = "Default";
	for(int k = 0; k < 4; k++){
		inv[k] = NULL;
	}
}
Character::Character(std::string const &name){
	_name = name;
	for(int k = 0; k < 4; k++){
		inv[k] = NULL;
	}
}
Character::Character(Character const &src){
	
}

Character::~Character(void){
	for (int k = 0; k < 4; k++){
		delete inv[k];
	}
}
Character	&Character::operator=(Character const &rhs){
	
}
/**************************METHOD*****************************/

std::string const & Character::getName() const{
	return (_name);
}

void Character::equip(AMateria* m) {
	if (i >= 0 && i < 4){
		inv[i] = m;
		std::cout << " The " << m->getType() << "is added to the location" << i << "of the inventary" << std::endl;
		i++;
	}
	else if (i >=4 || i < 0){
		std::cout << "The inventary is full" << std::endl;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4){
		if (inv[idx] != NULL){
			for (int k = idx; k < 4; k++){
				inv[k] = inv[k + 1];
			}
			i--;
		}else{
			std::cout << "Unequip is not possible : the location is empty !" << std::endl;
		}
		return ;
	}
	std::cout << "Unequip is not possible !: the index doesn't exist !" << std::endl;
}
void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx < 4 && inv[idx] != NULL){
		inv[idx]->use(target);
	}
	else if (idx < 0 || idx >=4){
		std::cout << "wrong inventary index" << std::endl;
	}
	else{
		std::cout << "no materia in this inventary location" << std::endl;
	}
}

